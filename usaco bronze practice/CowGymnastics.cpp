/*
first, create a 2d array of size N, N to keep track of times they were compared
this case, 1-4 is different than 4-1, which is necessary
based on the line we get, find all ways they can be compared and update the array
array keeps on updating
if any value in the array is equal to the number of sessions, we know this cow was consistent for all sessions
*/
#include <iostream>
using namespace std;

void printArray(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // K: num of session, N: num of cows
    int K, N;
    cin >> K >> N;
    // cout << K << " " << N << endl;

    // create a 2d array to keep track of comparations and how many times they show
    int compare[N][N];
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
             compare[x][y] = 0;
        }
    }
    // get rankings for one session at a time
    // update the 2d array for each spot
    for (int i = 0; i < K; i++) {
        int cowRank[N];
        for (int j = 0; j < N; j++) {
            cin >> cowRank[j];
        }
 
        // find all ways cows can be compared and update it in the array
        for (int x = 0; x < N; x++) {
            for (int y = x+1; y < N; y++) {
                compare[cowRank[x]-1][cowRank[y]-1]++;
            }
        }
        /*
        for (int j = 0; j < N; j++) {
            printArray(compare[j], N);
        }
        */
        // cout << "loop" << i << endl;
    }

    // if any value in the 2d array equals K, add to overall counter
    int counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (compare[i][j] == K) {
                counter++;
            }
        }
    }
    cout << counter << endl;
}
