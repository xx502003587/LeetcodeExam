/*
 * 题意：
 * 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 *
 * 思路：
 * 将数组从小到大排序，然后从中间分成小大两个部分。如果总长度为奇数，需保证小部分比大部分多一个数
 * 将大部分倒序放入数组的偶数位置，将小部分倒序放入数组的奇数部分
 * 一定可以构成摆动序列（具体证明过程尚不明白）
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void wiggleSort(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());

    auto tmp = nums;
    int k = len - 1;
    for (int i = 1; i < len; i += 2) {
        nums[i] = tmp[k--];
    }
    for (int i = 0; i < len; i += 2) {
        nums[i] = tmp[k--];
    }
}

int main() {
    vector<int> nums = {5,3,1,2,6,7,8,5,5};
    wiggleSort(nums); // 一种可能的结果 5,8,5,7,3,6,2,5,1
    return 0;
}