#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int max1, num1, max2, num2, max3, num3;
    cin >> max1 >> num1 >> max2 >> num2 >> max3 >> num3;

    int milk[4] = {0, num1, num2, num3};

    for (int i = 1; i <= 100; i++) {
        // 1, 4, 7 ... (bucket 1 to 2)
        if (i % 3 == 1) {
            if ((num1 + num2) > max2) {
                num1 = (num1 + num2) - max2;
                num2 = max2;
            }
            else {
                num2 = num1 + num2;
                num1 = 0;
            }
        }
        // bucket 2 to 3
        if (i % 3 == 2) {
            if ((num2 + num3) > max3) {
                num2 = (num2 + num3) - max3;
                num3 = max3;
            }
            else {
                num3 = num2 + num3;
                num2 = 0;
            }
        }
        // bucket 3 to 1
        if (i % 3 == 0) {
            if ((num3 + num1) > max1) {
                num3 = (num3 + num1) - max1;
                num1 = max1;
            }
            else {
                num1 = num1 + num3;
                num3 = 0;
            }
        }
    }

    cout << num1 << endl << num2 << endl << num3 << endl;
}