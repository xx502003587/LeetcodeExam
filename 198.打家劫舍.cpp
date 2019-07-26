/*
 * 动态规划
 * 令f[k]表示在前k个房屋中能得到的最大值，Ai表示在第i个房屋能得到的钱数
 * 则递推公式为：f[k] = max(f[k-2] + Ai, f[k-1])
 * 最大值要么是n-1房屋可盗窃的最大值，要么是n-2房屋最大值加当前房屋值，二者之间取较大的一个
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    vector<int> res(nums.size() + 1);
    res[0] = 0;
    res[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++) {
        // 由于初始化dp数组大小为nums.size()+1，所以当前房屋的值应该是i-1
        res[i] = max(res[i-1], res[i-2] + nums[i-1]);
    }
    return res.back();
}

int main() {
    vector<int> input = {1,2,3,1};
    auto ret = rob(input);
    cout << ret << endl;
    return 0;
}
