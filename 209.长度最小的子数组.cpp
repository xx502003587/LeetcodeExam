/*
 * 利用滑动窗口，在left ~ i之间进行滑动
 * 当sum < s时，右边界扩大
 * 当sum >= s时，更新长度，左边界缩小
 */

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int ret = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        while (sum >= s) {
            ret = min(ret, i - left + 1);
            sum -= nums[left++];
        }
    }
    return ret == INT_MAX ? 0 : ret;
}

int main() {
    vector<int> input = {2,3,1,2,4,3};
    auto ret = minSubArrayLen(7, input);
    cout << ret << endl;
    return 0;
}
