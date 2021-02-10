#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    // fill up an adjacent list for the graph
    vector<int> adj[num];
    for (int i = 0; i < num-1; i++) {
        int start, end;
        cin >> start >> end;
        adj[start-1].push_back(end);
        adj[end-1].push_back(start);
    }
    
    /* test by printing out input
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    // find the max num of values in a row in the adjacent  list
    int max = 0;
    for (int i = 0; i < num; i++) {
        int temp = adj[i].size();
        if (temp > max) {
            max = temp;
        }
    }

    cout << max+1 << endl;
}