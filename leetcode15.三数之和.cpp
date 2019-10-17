/*
 * 题意：
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
 * 找出所有满足条件且不重复的三元组。
 *
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> ret;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; ++i) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int j = i + 1, k = size - 1;
        while (j < k) {
            int tsum = nums[i] + nums[j] + nums[k];
            if (tsum > 0) {
                while (j < k && nums[k] == nums[--k]) {}
            } else if (tsum < 0) {
                while (j < k && nums[j] == nums[++j]) {}
            } else {
                ret.push_back(vector<int>{nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[++j]) {}
                while (j < k && nums[k] == nums[--k]) {}
            }
        }
    }

    return ret;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto ret = threeSum(nums);
    for (auto out : ret) {
        for (auto in : out) {
            cout << in << " ";
        }
        cout << endl;
    }
    return 0;
}

