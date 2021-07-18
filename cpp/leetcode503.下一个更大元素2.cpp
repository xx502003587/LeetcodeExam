/*
 * 题意：
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
 * 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
 * 如果不存在，则输出 -1。
 *
 * 思路：
 * 与leetcode496题类似，只不过496题中遍历到数组末尾就停止了
 * 而此题中遍历到数组末尾还应该循环到数组起始位置，直到转一圈之后到当前位置，才算做查找结束
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    vector<int> ret;
    if (!size) {
        return ret;
    }
    for (int i = 0; i < size; i++) {
        int t = 0;
        for (; t < size - 1; t++) {
            int j = (i+1+t) % size;
            if (nums[j] > nums[i]) {
                ret.push_back(nums[j]);
                break;
            }
        }
        if (t == size - 1) {
            ret.push_back(-1);
        }
    }
    return ret;
}

int main() {
    vector<int> nums = {1,2,1};
    auto ret = nextGreaterElements(nums);
    for (auto num : ret) {
        cout << num << " ";
    }
    return 0;
}
