//
//  main.cpp
//  NoTimetoPaint
//
//  Created by Hannah Zhang on 2/5/21.
//

#include <iostream>
#include <string>
using namespace std;

void print1darray(int str[], int size) {
    for (int i = 0; i < size; i++) {
        cerr << str[i] << " ";
    }
    cerr << endl;
}

int main() {
    int N, Q; // N = fence size & Q = various tests
    cin >> N >> Q;
    
    string fence;
    cin >> fence;
    
    // from the fence, go through it and compute how many strokes are needed at each value an store in an array (from left and right side to later add together)
    int prefix[N+1];
    int suffix[N+1];
    // keep another array that tracks all characters seen before and when they were seen
    int seen[26];
    // all chars start as not being seen
    for (int i = 0; i < 26; i++) {
        seen[i] = -1;
    }
    // find the prefix (aka the left side of the section)
    // now iterate through the fence from left to right, going one by one and adding previous value with the value computed through if statements
    prefix[0] = 0; // set the base case
    for (int i = 1; i < N+1; i++) {
        // tells us if we have seen the next fence val
        int seenInd = fence[i-1] - 'A'; // tells us the index of the char
        int seenValue = seen[seenInd];
        if (seenValue == -1) {
            prefix[i] = prefix[i-1]+1; // value = past string val + 1
        } else {
            // assume all the values in between are greater and only update if the if statement is triggered
            prefix[i] = prefix[i-1];
            for (int j = seenValue+1; j < i-1; j++) {
                // if at least one value in between is smaller than most recent sighting
                if (fence[j] < fence[i-1]) {
                    prefix[i] = prefix[i-1]+1; // add because it was not consecutive
                    break;
                }
            }
        }
        seen[seenInd] = i-1; // update seenInd to most recent sighting
    }
    // find the suffex (aka the right side of the section)
    // now iterate through the fence from right to left, going one by one and adding previous value with the value computed through if statements
    int lastSeen[26];
    for (int i = 0; i < 26; i++) {
        lastSeen[i] = -1;
    }
    suffix[N] = 0;
    suffix[N-1] = 1;
    lastSeen[fence[N-1]-'A'] = N-1;
    for (int i = N-2; i >= 0; i--) {
        int charIndex = fence[i] - 'A';
        int lastSeenArrValue = lastSeen[charIndex];
        if (lastSeenArrValue == -1) {
            suffix[i] = suffix[i+1]+1;
        }
        else {
            suffix[i] = suffix[i+1];
            for (int j = i; j < lastSeenArrValue; j++) {
                if (fence[j] < fence[lastSeenArrValue]) {
                    suffix[i] = suffix[i+1]+1;
                    break;
                }
            }
        }
        lastSeen[charIndex] = i;
        //cerr << charIndex << " " << lastSeenArrValue << " " << suffix[i] << " " << lastSeen[charIndex] << " \n";
    }
    
    //print1darray(prefix, N+1);
    //print1darray(suffix, N);
    // after computing prefix and suffix, determine the gap and add
    for (int i = 0; i < Q; i++) {
        int begin, end;
        cin >> begin >> end;
//        if (end == N) {
//            cout << prefix[begin-1] << endl;
//        } else {
//            cout << prefix[begin-1] + suffix[end] << endl;
//        }
        cout << prefix[begin-1] + suffix[end] << endl;
    }
}

