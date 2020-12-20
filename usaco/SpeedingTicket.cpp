#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int lawspeed[N], lawlen[N], cowspeed[M], cowlen[M];

    // read in length and speed input for the law
    for (int i = 0; i < N; i++) {
        cin >> lawlen[i] >> lawspeed[i];
    }

    // cow input
    for (int i = 0; i < M; i++) {
        cin >> cowlen[i] >> cowspeed[i];
    }

    // create arrays to track for each mile for the law
    int x = 0;
    int law[100], cow[100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < lawlen[i]; j++) {
            law[j+x] = lawspeed[i];
        }
        x = x + lawlen[i];
    }

    // create array to track for each mile for the cow
    int y = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < cowlen[i]; j++) {
            cow[j+y] = cowspeed[i];
        }
        y = y + cowlen[i];
    }

    // find max speed she was over, if at all
    int max = 0;
    for (int i = 0; i < 100; i++) {
        int currentMax = cow[i] - law[i];
        if (currentMax > 0) {
            if (currentMax > max) {
                max = currentMax;
            }
        }
        // cout << max << endl;
    }

    /*
    for (int i = 0; i < 100; i++) {
        cout << cow[i] << " " << endl;
    } */

    cout << max << endl;
}
