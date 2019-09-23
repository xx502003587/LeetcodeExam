/*
 * 题意：
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 *
 * 思路：
 * 类似于字符串翻转的思路
 * 首先将整个数组进行翻转，然后将前k个翻转，后n-k个再翻转即可
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start++], nums[end--]);
    }
}

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= nums.size();
    reverse(nums, 0, len-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, len-1);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    for (auto num : nums) {
        cout << num << " ";
    }
    return 0;
}
