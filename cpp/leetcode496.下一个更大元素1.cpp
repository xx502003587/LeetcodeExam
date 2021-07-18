/*
 * 题意：
 * 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
 * 找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
 * nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
 * 如果不存在，对应位置输出-1。
 * 
 * 思路：
 * 首先用一个 map 将 nums2 中所有数与其下标的对应关系存储起来
 * 然后遍历 nums1 中的每个数，通过 map 查询到其在 nums2 中的对应位置
 * 然后从该位置起往右遍历，找到第一个比他大的数，加入结果集即可
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    // 记录 数 和 下标 的对应关系
    for (int i = 0; i < nums2.size(); ++i) {
        m[nums2[i]] = i;
    }
    vector<int> ret;
    for (int i = 0; i < nums1.size(); ++i) {
        int j = m[nums1[i]] + 1;
        for (; j < nums2.size(); ++j) {
            if (nums2[j] > nums1[i]) {
                ret.push_back(nums2[j]);
                break;
            }
        }
        if (j == nums2.size()) {
            ret.push_back(-1);
        }
    }
    return ret;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    auto ret = nextGreaterElement(nums1, nums2);
    for (auto num : ret) {
        cout << num << " ";
    }
    return 0;
}
