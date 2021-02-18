#include <iostream>
#include <vector>
using namespace std;

// writing prefix sum
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // define the prefixsum vector (automatically has all 0's)
    int length = nums.size();
    vector<int> prefixsum(length+1);
    for (int i = 0; i < length; i++) {
        // add the previous value in prefixsum with current input value
        prefixsum[i+1] = prefixsum[i] + nums[i];
    }

    // print prefixsum
    for (int i = 0; i < prefixsum.size(); i++) {
        cout << prefixsum[i] << " ";
    }
}
