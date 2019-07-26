/*
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int count = 1;

    int cur = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            cur = nums[i];
        }
        count = nums[i] == cur ? count+1 : count-1;
    }
    return cur;
}


int main() {
    vector<int> input = {3,2,3};
    auto count = majorityElement(input);
    cout << count << endl;

    return 0;
}
