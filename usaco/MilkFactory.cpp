#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// define the adjacent list and boolean
vector<int> adj[100];
bool visited[100];

// use depth-first search in adjacent list to check to see if it is possible
// to move from one node to all the other nodes
void dfs(int node) {
    if (visited[node] == true) {
        return;
    } else {
        visited[node] = true;
        for (auto u: adj[node]) {
            dfs(u);
        }
    }
}

void print(vector<int> adj[], int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;

    // fill up an adjacent list for the graph
    for (int i = 0; i < num-1; i++) {
        int start, end;
        cin >> start >> end;
        adj[end-1].push_back(start-1);
    }

    int answer = -1;
    for (int i = 0; i < num; i++) {
        // reset visited array for each node
        for (int z = 0; z < num; z++) {
            visited[z] = false;
        }
        // call dfs
        dfs(i);
        bool allTrue = true;
        for (int j = 0; j < num; j++) {
            if (visited[j] == false) {
                allTrue = false;
                break;
            }
        }
        // if it ends up here, it means there is a false
        if (allTrue == true) {
            answer = i;
            break;
        }
    }
    if (answer != -1) {
        answer++;
    }
    cout << answer << endl;
}
