#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;

    int lower[N], upper[N];
    string type[N];

    for (int i = 0; i < N; i++) {
        cin >> type[i] >> lower[i] >> upper[i];
    }

    // compute after range (ignore on and off before a none)
    // get num where none starts
    int count = 0;
    while (type[count] != "none") {
        count++;
    }
    
    // start from count value
    int xaft = lower[count], yaft = upper[count];
    for (int i = count + 1; i < N; i++) {
        if (type[i] == "none") {
            xaft = max(xaft, lower[i]);
            yaft = min(yaft, upper[i]);
        } if (type[i] == "on") {
            xaft = xaft + lower[i];
            yaft = yaft + upper[i];
        } if (type[i] == "off") {
            xaft = xaft - upper[i];
            yaft = yaft - lower[i];
        }
    }

    // compute after range (same thing as before except backwards)
    int count2 = N-1;
    while (type[count2] != "none") {
        count2--;
    }
    int xbef = lower[count2], ybef = upper[count2];
    for (int i = count2 - 1; i >=0; i--) {
        if (type[i] == "none") {
            xbef = max(xbef, lower[i]);
            ybef = min(ybef, upper[i]);
        }
        if (type[i] == "on") {
            xbef = xbef - upper[i];
            ybef = ybef - lower[i];
        }
        if (type[i] == "off") {
            xbef = xbef + lower[i];
            ybef = ybef + upper[i];
        }
    }

    cout << xbef << " " << ybef << endl;
    cout << xaft << " " << yaft << endl;
    

}
