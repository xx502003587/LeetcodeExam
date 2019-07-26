/*
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        auto aa = to_string(a);
        auto bb = to_string(b);
        return aa + bb > bb + aa;
    });

    if (nums[0] == 0) {
        return "0";
    }

    string ret;
    for (auto num : nums) {
        ret.append(to_string(num));
    }
    return ret;
}

int main() {
    vector<int> nums = {3,30,34,5,9};
    auto ret = largestNumber(nums);
    cout << ret << endl;

    return 0;
}
