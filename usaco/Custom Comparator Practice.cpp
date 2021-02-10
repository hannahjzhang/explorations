#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

// custom comparators means you make another function that you can then pass into the sort function to customize how it can be sorted

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    // solely looking at the second column)
    int part1 = a.second.first;
    int part2 = b.second.first;
    // if part1 is less than part2, return true
    // this means it will be sorted by ascending order
    return part1 < part2;
    // on another note, if part1>part2, it will be sorted by descending order
}

bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    // solely looking at the second column)
    int part1 = a.second.second;
    int part2 = b.second.second;
    return part1 < part2;
}

int main() {
    int M = 4;
    vector<pair<int,pair<int,int>>> v;
    for (int i = 0; i < M; ++i) {
        int a,b,w; cin >> a >> b >> w;
        v.push_back({w,{a,b}});
    }
    sort(begin(v),end(v), compare);
    for (auto e: v) cout << e.s.f << " " << e.s.s << " " << e.f << "\n";
    sort(begin(v),end(v), compare2);
    for (auto e: v) cout << e.s.f << " " << e.s.s << " " << e.f << "\n";
}