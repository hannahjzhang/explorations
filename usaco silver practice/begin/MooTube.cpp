#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<pair<int, int>> adj[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j].first << " " << adj[i][j].second << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // read in and create the adjacency list
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < N-1; i++) {
        int first, second, length;
        cin >> first >> second >> length;
        adj[first-1].push_back({second-1, length});
        adj[second-1].push_back({first-1, length});
    }

    // print(adj, N);

    // instantiate things for bfs later
    queue<int> q;
    bool visited[N];
    // instantiate relevance and fill it up with large numbers
    int relevance[N];
    // read in the questions (k is minimum relevancy, v is current vid)
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        v-- ;
        // fill up relevance and visited
        for (int j = 0; j < N; j++) {
            relevance[j] = 1000000001;
            visited[j] = false;
        }

        // initiate counter for how many videos are relevant from current node
        int counter = 0;
        // bfs algorithm
        visited[v] = true;
        q.push(v);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            // process node v
            for (auto u : adj[s]) {
                if (visited[u.first]) continue;
                visited[u.first] = true;
                int currRelevance = u.second;
                // cout << "currrel: " << currRelevance << endl;
                // update relevance arrays to have the min values
                if (currRelevance >= k) {
                    counter++;
                    q.push(u.first);
                }
            }
        }

        // print the relevance
        cout << counter << endl;

    }

}
