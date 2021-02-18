//
//  main.cpp
//  Cowntagion
//
//  Created by Hannah Zhang on 2/6/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 100000;
vector<int> connections[maxN+1];

// print adjacency list function
void printadj(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < connections[i].size(); j++) {
            cout << connections[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N; // number of farms
    
    // read in farm connection data as an adjacency list
    for (int i = 0; i < N-1; i++) {
        int start, end;
        cin >> start >> end;
        start--; end--;
        connections[start].push_back(end);
        // ** must make it two way since possible data includes travelling from large to small nums
        // ** this algorithm accounts for both in degree & out degree
        connections[end].push_back(start);
    }
    // sort(connections, connections+N);
    // printadj(N);
    // find out how many children each row index has, must allow it to double until num (starting from 1) is greater than num of nodes
    int steps = 0;
    for (int i = 0; i < N; i++) { // iterate through adjacency list
        // -1 to account for the in-feeding-node from the 2-way adjacency list
        int currSize = 0;
        // no need to subtract one for size when i = 0, since there is no incoming node
        if (i != 0) {
            currSize = (int) connections[i].size() - 1;
        } else {
            currSize = (int) connections[i].size();
        }
        int counter = 1; // number of infected in one farm
        // keep doubling until
        int localstep = 0;
        while (counter <= currSize) {
            counter = counter * 2;
            localstep++;
            // cout << i << " " << steps << endl;
        }
        // cout << "size:" << currSize << " #=" << localstep << endl;
        steps += localstep;
    }
    // cout << steps << endl;
    cout << steps+N-1 << endl;
}
