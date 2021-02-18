//
//  main.cpp
//  DanceMooves
//
//  Created by Hannah Zhang on 1/31/21.
//

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

void print1darr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print1dvec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cerr << vec[i] << " ";
    }
    cerr << endl;
}

void printsetarr(set<int> arr[], int N) {
    for (int i = 0; i < N; i++) {
        for(auto v : arr[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// during dfs, track who has been visited
bool visited[100000];
// create a vector that has the total places one starting place will visit
vector<int> visitedVal;
void dfs(int node, int graph[], int N) {
    if (visited[node] == true) {
        return;
    } else {
        visited[node] = true;
        visitedVal.push_back(node);
        dfs(graph[node], graph, N);
    }
}

int main(int argc, const char * argv[]) {
    //ifstream fin ("/Users/hannahzhang/Documents/C++ Practice/Silver Practice/February Practice/prob1_silver_jan21/11.in");
    // read input and put into two adjacency lists
    int N, K; // N is number of cows, K is number of times swapped
    cin >> N >> K;
    
    int finalPlace[N];
    set<int> where[N];
    // fill up both accordingly
    for (int i = 0; i < N; i++) {
        finalPlace[i] = i;
        where[i].insert(i);
    }
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // add to the where it has been set list
        where[finalPlace[a]].insert(b);
        where[finalPlace[b]].insert(a);
        swap(finalPlace[a], finalPlace[b]);
    }
    
    // print1darr(finalPlace, N);
    // printsetarr(where, N);
    // put the finalPlace array into a graph
    int graph[N];
    for (int i = 0; i < N; i++) {
        graph[finalPlace[i]] = i;
    }
    // print1darr(graph, N);
    // use dfs to go through final places graph and track all final places possible
    // use those values as indices to merge sets
    // find the length of the set
    // store in answer array
    int answer[N];
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        dfs(i, graph, N);
        // print1dvec(visitedVal);
        // now that we have visited val, merge the corresponding set values
        set<int> val;
        for (int j = 0; j < visitedVal.size(); j++) {
            val.insert(where[visitedVal[j]].begin(), where[visitedVal[j]].end());
        }
        int length = (int) val.size();
        for (int k = 0; k < visitedVal.size(); k++) {
            answer[visitedVal[k]] = length;
        }
        visitedVal.resize(0);
    }
    
    // print out answer array
    for (int i = 0; i < N; i++) {
        cout << answer[i] << endl;
    }
}
