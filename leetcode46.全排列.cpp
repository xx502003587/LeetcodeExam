/*
 * 回溯
 * 每次循环逐个判断数字有没有出现，没有则加入该数字进行递归
 * 递归结束之后去掉该数字，回溯到上一种情况
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void dfs(vector<int>& nums, vector<int> tmp, int start, vector<vector<int>>& result) {
    if (tmp.size() == nums.size()) {
        result.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        // 判断数字是否已经加入序列中
        if (count(tmp.begin(), tmp.end(), nums[i]) > 0) {
            continue;
        }
        // 没有加入则将其加入，进行递归
        tmp.push_back(nums[i]);
        dfs(nums, tmp, i+1, result);
        // 递归结束之后，当前位置以该数字开始的情况都已经结束，回溯到前一种情况
        tmp.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) {
        return result;
    }
    vector<int> tmp;
    dfs(nums, tmp, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4};
    auto ret = permute(nums);
    for (auto v : ret) {
        for (auto item : v) {
            cout << item ;
        }
        cout << endl;
    }
    return 0;
}