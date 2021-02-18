//
//  main.cpp
//  StuckInARut
//
//  Created by Hannah Zhang on 2/13/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1001;
int xVal[maxN];
int yVal[maxN];
bool stopped[maxN];
int blocked[maxN];

void print1darr (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cerr << arr[i] << " ";
    }
    cerr << endl;
}

void print1dvec (vector<int> vec) {
    for (auto i : vec) {
        cerr << i << " ";
    }
    cerr << endl;
}

bool compareX(int a, int b) {
    // < means sort by ascending order
    return xVal[a] < xVal[b];
}

bool compareY(int a, int b) {
    // < means sort by ascending order
    return yVal[a] < yVal[b];
}

int main() {
    int N;
    cin >> N;
    
    vector<int> northInd;
    vector<int> eastInd;
    for (int i = 0; i < N; i++) {
        // put x and y coordinates somewhere
        int x; int y; char dir;
        cin >> dir >> x >> y;
        x--; y--;
        xVal[i] = x;
        yVal[i] = y;
        // put cow index (aka name)
        if (dir == 'E') {
            eastInd.push_back(i);
        }
        else {
            northInd.push_back(i);
        }
    }
    // sort east by y-axis, sort north by x-axis
    sort(eastInd.begin(), eastInd.end(), compareY);
    sort(northInd.begin(), northInd.end(), compareX);
    
//    print1darr(xVal, N);
//    print1darr(yVal, N);
//    print1dvec(eastInd);
//    print1dvec(northInd);
    
    // compute distance between the two at the intersection
    // using auto means that i and j give us the value of the actual cow not the index
    for (auto e : eastInd) { // iterates through east
        for (auto n : northInd) { // each time iteratures through north
            
            // first check if any cows are stopped and if yes, continue
            if (stopped[e] == true || stopped[n] == true) {
                continue;
            }
            
            // if any cows have passed the point of intersection, continue
            if ((yVal[e] < yVal[n]) || (xVal[e] > xVal[n])) {
                continue;
            }
            
            // if it goes here, both cows have not been stopped and will intersect soon
            // find if east and north cow dist between intersection
            int xDist = xVal[n] - xVal[e];
            int yDist = yVal[e] - yVal[n];
            
            if (xDist < yDist) { // east cow stops north
                stopped[n] = true;
                blocked[e] += (blocked[n] + 1); // must pass the ones the other has blocked to this one
            }
            else if (yDist < xDist){ // north cow stops east
                stopped[e] = true;
                blocked[n] += (blocked[e] + 1);
            }
            else { // equal
                continue;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << blocked[i] << endl;
    }
}
