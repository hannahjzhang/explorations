//
//  main.cpp
//  RectangularPasture
//
//  Created by Hannah Zhang on 2/13/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
const int maxN = 2501;
pair<int, int> points[maxN];
int prefix[maxN][maxN];

bool compareY(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void printpair(pair<int, int> arr[], int size) {
    for (int i = 0; i < size; i++) {
        cerr << arr[i].first << " " << arr[i].second << endl;
    }
}

void printarr(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cerr << prefix[i][j] << " ";
        }
        cerr << endl;
    }
}

int main() {
    cin >> N;
    // read the points into a 2d vector
    for (int i = 0; i < N; i++) {
        int x; int y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    
    // compact the array in the x
    sort(points, points+N); // automatically sorts the first
    for (int i = 0; i < N; i++) {
        points[i].first = i;
    }
    
    // compact in the y direction
    sort(points, points+N, compareY);
    for (int i = 0; i < N; i++) {
        points[i].second = i;
    }
    // printpair(points, N);
    
    // set areas with cows to 1 on the prefix array
    for (int i = 0; i < N; i++) {
        int xCoord = points[i].first;
        int yCoord = points[i].second;
        prefix[xCoord + 1][yCoord + 1] = 1;
    }
    // compute prefix sum, remember to add a row & col extra
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    // printarr(N+1);
    
    // use prefix sums and previously determined formula to compute possibilities, add it to the counter
    long long possible = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            // find the next possible rectangle combo
            int minX = min(points[i].first, points[j].first);
            int maxX = max(points[i].first, points[j].first);
            pair<int, int> topCorner = make_pair(minX, points[i].second);
            pair<int, int> bottomCorner = make_pair(maxX, points[j].second);
            
            // check point i with every points after
            // multiply leftSum and rightSum
            int x1 = topCorner.first+1; int y1 = topCorner.second+1;
            int x2 = bottomCorner.first+1; int y2 = bottomCorner.second+1;
//
            int leftNum = prefix[x1][y2] - prefix[x1][y1-1];
            int rightNum = prefix[N][y2] - prefix[N][y1-1] - prefix[x2-1][y2] + prefix[x2-1][y1-1];
            
            int toAdd = leftNum * rightNum;
            possible += toAdd;
//            cout << topCorner.first << ", " << topCorner.second << endl;
//            cout << bottomCorner.first << ", " << bottomCorner.second << endl;
//            cout << leftNum << " " << rightNum << " " << possible << endl;
//            cout << endl;
        }
    }
    // add all the combos + the total grid + the individual grid fences
    cout << possible+N+1 << endl;
}
