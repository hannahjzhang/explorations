#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int max[N], num[N];
    for (int i = 0; i < N; i++) {
        cin >> max[i] >> num[i];
    }

    for (int i = 0; i < 100; i++) {
        // 1 --> bucket 0 ...
        int bucket = i % N;
        // next bucket using circular manipulation
        int next = (bucket+1) % N;

        // common algorithm using bucket and next values
        if (num[bucket] + num[next] > max[next]) {
            num[bucket] = (num[bucket] + num[next]) - max[next];
            num[next] = max[next];
        }
        else {
            num[next] = num[bucket] + num[next];
            num[bucket] = 0;
        }
    }

    // output
    for (int i = 0; i < N; i++) {
        cout << num[i] << endl;
    }
}
