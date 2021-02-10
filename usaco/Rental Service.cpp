#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printv(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << endl;
    }
    cout << endl;
}

void printa(int a[], int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " " << endl;
    }
}

void printp(vector<pair<int, int>> p) {
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].first << " " << p[i].second << endl;
    }
    cout << endl;
}

// use custom comparator to sort the two vector pair by unit price
bool compare(pair<int, int> a, pair<int, int> b) {
    int part1 = a.first;
    int part2 = b.first;
    return part1 > part2;
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    // create vector for cow milk amount
    vector<int> amount;
    for (int i = 0; i < N; i++) {
        int currAmount;
        cin >> currAmount;
        amount.push_back(currAmount);
    }

    // create vector of pairs for buyer amount/price
    vector<pair<int, int>> buyer;
    for (int i = 0; i < M; i++) {
        int gallons, unitprice;
        cin >> gallons >> unitprice;
        buyer.push_back(make_pair(unitprice, gallons));
    }

    // create vector for renter prices
    vector<int> renter;
    for (int i = 0; i < R; i++) {
        int rentprice;
        cin >> rentprice;
        renter.push_back(rentprice);
    }

    // sort the vector in largest to smallest order
    sort(begin(amount), end(amount));
    reverse(amount.begin(), amount.end());
    sort(begin(buyer), end(buyer), compare);
    sort(begin(renter), end(renter));
    reverse(renter.begin(), renter.end());

    // printv(amount);
    // printp(buyer);
    // printv(renter);

    // create an array that calculates each cow's max profit for selling
    // keeping in mind that other cows may have gone before
    int cowprofit[N];
    for (int i = 0; i < N; i++) {
        cowprofit[i] = 0;
    }
    int counter = 0;
    int whichcow = amount[counter];
    for (int i = 0; i < M; i++) {
        // when this loop exits, the first buyer will be done
        while (buyer[i].second != 0) {
            if (whichcow == 0) {
                counter++;
                whichcow = amount[counter];
                cowprofit[counter] += buyer[i].first;
                whichcow--;
                buyer[i].second--;
            } else {
                cowprofit[counter] += buyer[i].first;
                whichcow--;
                buyer[i].second--;
            }
        }
    }

    // from the end of the cow milk selling array, replace with renter and check price
    int max = 0;
    // find the max of the cow profit array and renting profit array
    // if num of cows is greater or equal to num of renters, use renters
    int countagain = 0;
    int wheretoend = 0;
    if (N > M) {
        wheretoend = N-M;
    }
    for (int i = N-1; i >= wheretoend; i--) {
        if (cowprofit[i] < renter[countagain]) {
            cowprofit[i] = renter[countagain];
            countagain++;
        }
        // because it is sorted, if it is greater, nothing else will work
        else {
            break;
        }
    }

    // printa(cowprofit, N);

    // calculate sum profit
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += cowprofit[i];
    }
    cout << sum << endl;
}
