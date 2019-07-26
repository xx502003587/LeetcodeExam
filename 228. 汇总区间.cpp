/*
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> ret;
    for (int i = 0, j = 0; i < n; ++i) {
        if (i + 1 < n && nums[i+1] == nums[i] + 1) {
            continue;
        }
        if (i == j) {
            ret.push_back(to_string(nums[j]));
        } else {
            ret.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
        }
        j = i + 1;
    }
    return ret;
}


int main() {
    vector<int> input = {0,1,2,4,5,7};
    auto ret = summaryRanges(input);
    for (auto item : ret) {
        cout << item << " " << endl;
    }
    return 0;
}
