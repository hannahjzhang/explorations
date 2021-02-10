/* 
first, determine all possible ways to showcase using 0s and 1s
then using that, convert to strings for each row
in a loop, find the number of each letter of the alphabet in the row and check with current max
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// generates the next line of 0/1s which represents either side of the board
void lineGenerator(int nums, int temp[], int x) {
    // create an array of all 0
    for (int i = 0; i < nums; i++) {
        temp[i] = 0;
    }
    // update some to 1s as necessary
    int counter = 0;
    while (x > 0) {
        temp[counter] = x % 2;
        x = x / 2;
        counter++;
    }
    
}

int main() {
    int N;
    cin >> N;

    string front[N], back[N];
    for (int i = 0; i < N; i++) {
        cin >> front[i] >> back[i];
    }
    
    // after getting string of all words combinations, find num of each letter
    int numTimesFinal[26];
    // fill up numTimes with zeroes
    for (int i = 0; i < 26; i++) {
        numTimesFinal[i] = 0;
    }

    for (int i = 0; i < pow(2, N); i++) {
        // call the function to get the next line of 0s and 1s
        int values[N];
        lineGenerator(N, values, i);
        // based on front/back, create a string
        string row;
        for (int k = 0; k < N; k++) {
            if (values[k] == 0) {
                row = row + front[k];
            } else {
                row = row + back[k];
            }
        }
        // create temporary numTimes array that will later get cleaned
        int numTimes[26];
        for (int i = 0; i < 26; i++) {
            numTimes[i] = 0;
        }
        // given the string, calculate number of each letter present
        for (int j = 0; j < row.size(); j++) {
            numTimes[row[j]-'a']++;
        }
        for (int j = 0; j < 26; j++) {
            numTimesFinal[j] = max(numTimesFinal[j], numTimes[j]);
        }
    }

    // final: print out each value in the array --> num of appeareances
    for (int i = 0; i < 26; i++) {
        cout << numTimesFinal[i] << endl;
    }
    
}
