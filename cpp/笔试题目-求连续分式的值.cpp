/*
 * 题意：
 * 求连续分式的值，分式的形式为（分步写开较容易理解）：
 * y  = a0 + 1/t0
 * t0 = a1 + 1/t1
 * t1 = a2 + 1/t2
 * t2 = a3 + 1/t4
 * ……
 * 即 y = a0 + 1/ (a1 + 1/ (a2 + 1/ (a3 + 1/ ())))
 * 输入为a0 a1 a2 a3……的值，输出最后结果的分数形式
 * 如输入 3 2 0 2，输出13 4，即4分之13
 * 
 * 思路：
 * 递归方法
 * 每一个分式都是相同的形式，递归到最后一个分式，计算出结果，向上返回一层一层计算结果
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void func(const vector<int>& nums, int start, pair<int, int>& res) {
    // 当没有递归到最后一个数时
    if (start < nums.size() - 1) {
        // 先进行递归
        func(nums, start+1, res);
        // 将递归计算返回的值进行分子分母的颠倒，因为有一个倒数计算
        swap(res.first, res.second);
        // 将当前的数加到分数中去
        res.first += nums[start] * res.second;
    }
    // 当递归到最后一个数时，只剩下这个数本身，所以直接将分子设置为当前数，分母设置为1
    else if (start == nums.size() - 1) {
        res.first = nums[start];
        res.second = 1;
    }
}

int main() {
    vector<int> nums = {3,2,0,2};
    // 存储分子和分母
    pair<int, int> res = {0,0};
    func(nums, 0, res);
    cout << res.first << "#" << res.second; // 13#4
    return 0;
}

