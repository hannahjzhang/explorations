//
//  main.cpp
//  SpacedOut
//
//  Created by Hannah Zhang on 2/6/21.
//

#include <iostream>
#include <algorithm>
using namespace std;

int pasture[1001][1001]; // make this global
int transpose[1001][1001]; // test the other pasture case

// print pasture function
void print2darr(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << pasture[i][j] << " ";
        }
        cout << endl;
    }
}

// create a function that goes through the columns one by one and in each column, determine whether placement in 1/3/etc or 2/4/etc is better
int determine(int size, int currentCol) {
    int startZero = 0;
    int startOne = 0;
    // find 0/2/4, etc total beauty val
    for (int i = 0; i < size; i=i+2) {
        startZero += pasture[i][currentCol];
    }
    // find 1/3/5, etc total beauty val
    for (int j = 1; j < size; j=j+2) {
        startOne += pasture[j][currentCol];
    }
    // return the max value
    return max(startZero, startOne);
}

int main() {
    int N;
    cin >> N; // size of the field
    
    // fill up pasture beauty values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pasture[i][j];
        }
    }
    
    // use the function to determine best placement and then add to the beauty counter
    // include the alternating column case & alternating row case and find max
    int beauty1 = 0;
    int beauty2 = 0;
    for (int i = 0; i < N; i++) {
        beauty1 += determine(N, i);
    }
    // transpose the pasture for the second test case (doing this the way without creating another matrix - swapping the two sides across the diagonal)
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            swap(pasture[i][j], pasture[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
        beauty2 += determine(N, i);
    }
    cout << max(beauty1, beauty2) << endl;
}
