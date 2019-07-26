/*
 * 动态规划
 * 令f[k]表示在前k个房屋中能得到的最大值，Ai表示在第i个房屋能得到的钱数
 * 则递推公式为：f[k] = max(f[k-2] + Ai, f[k-1])
 * 因为房屋是环形排列，所以第一个和最后一个是相邻的
 * 所以可以使用198的方法，分成两种情况进行选择
 * 1. 从第1号屋子到n-1号屋子
 * 2. 从第2号屋子到n号屋子
 * 取二者之间的最大值即可
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> res0(nums.size() + 1);
    vector<int> res1(nums.size() + 1);

    // 从第一家开始，不偷最后一家
    res0[1] = nums[0];
    res0[2] = max(nums[0], nums[1]);
    for (int i = 3; i < nums.size(); ++i) {
        res0[i] = max(res0[i-1], res0[i-2] + nums[i-1]);
    }
    // 从第二家开始，可以偷最后一家
    res1[2] = nums[1];
    res1[3] = max(nums[1], nums[2]);
    for (int i = 4; i <= nums.size(); ++i) {
        res1[i] = max(res1[i-1], res1[i-2] + nums[i-1]);
    }

    return max(res0[nums.size()-1], res1.back());
}

int main() {
    vector<int> input = {2,3,2};
    auto ret = rob(input);
    cout << ret << endl;
    return 0;
}
