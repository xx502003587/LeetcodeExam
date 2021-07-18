/*
 * 题意：
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 要求：
 * 输出结果中的每个元素一定是唯一的。
 *
 * 思路：
 * 使用一个map存储第一个数组中的每个数，key为数，value为1，表示该数出现过
 * 遍历第二个数组，对于每一个数判断map中是否有这个数作为key
 * 如果有表明两个数组都出现，加入结果集
 * 如果没有表明只有第二个数组才出现
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m1;
    for (auto item : nums1) {
        if (m1.count(item) == 0) {
            m1[item] = 1;
        }
    }

    vector<int> result;
    for (auto item : nums2) {
        if (m1.count(item) > 0) {
            result.push_back(item);
            m1.erase(item);
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    auto ret = intersection(nums1, nums2); // 2
    for (auto num : ret) {
        cout << num << endl;
    }
    return 0;
}