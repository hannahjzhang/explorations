#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, a, b, c;
    int one[4] = {0, 1, 0, 0};
    int two[4] = {0, 0, 1, 0};
    int three[4] = {0, 0, 0, 1};
    int oneCount = 0, twoCount = 0, threeCount = 0;

    cin >> N;
    // cout << N << endl;
    // fill up arrays A, B, C
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        swap(one[a], one[b]);
        swap(two[a], two[b]);
        swap(three[a], three[b]);

        if (one[c] == 1) {
            oneCount++;
        }
        if (two[c] == 1) {
            twoCount++;
        }
        if (three[c] == 1) {
            threeCount++;
        }
    }

    // cout << oneCount << " " << twoCount << " " << threeCount << endl;
    int temp = max(oneCount, twoCount);
    int highest = max(temp, threeCount);
    cout << highest << endl;
}