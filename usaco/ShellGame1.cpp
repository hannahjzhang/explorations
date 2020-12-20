#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, A[100], B[100], C[100];
    cin >> N;
    // fill up arrays A, B, C
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    // method 1: {1, 0, 0}
    int one[4] = {0, 1, 0, 0}; // for indexing purposes
    int oneCount = 0;
    for (int i = 0; i < N; i++) {
        swap(one[A[i]], one[B[i]]);
        if (one[C[i]] == 1) {
            oneCount++;
        }
    }

    // method 2
    int two[4] = {0, 0, 1, 0};
    int twoCount = 0;
        for (int i = 0; i < N; i++) {
        swap(two[A[i]], two[B[i]]);
        if (two[C[i]] == 1) {
            twoCount++;
        }
    }

    // method 3
    int three[4] = {0, 0, 0, 1};
    int threeCount = 0;
        for (int i = 0; i < N; i++) {
        swap(three[A[i]], three[B[i]]);
        if (three[C[i]] == 1) {
            threeCount++;
        }
    }

    int temp = max(oneCount, twoCount);
    int highest = max(temp, threeCount);
    cout << highest << endl;
}