/*
 * 题意：
 * 学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。
 * 请你返回至少有多少个学生没有站在正确位置数量。该人数指的是：能让所有学生以 非递减 高度排列的必要移动人数
 * 1 <= heights.length <= 100，1 <= heights[i] <= 100
 * 
 * 思路：
 * 想要知道有多少学生没有站在正确的位置，只需要将所有人都正确的站位与其对比，当两个相同位置的人不同时，就表明该学生没有站对位置
 * 利用桶排序的思想
 * 由于已经知道了人数不会超过100人，所以可以维护一个长度为100的数组bucket
 * 其中 bucket[i] 表示高度为 i 的人有多少个
 * 遍历身高序列，将对应身高的人数统计到 bucket 数组中去
 * 
 * 然后从前到后遍历 bucket 数组，相当于遍历正确站位的有序数组，对比当前的站位如果不相同就对结果累加1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> bucket(101, 0);
    for (auto num : heights) {
        bucket[num]++;
    }
    int cnt = 0;
    for (int i = 1, j = 0; i < bucket.size(); ++i) {
        while (bucket[i]-- > 0) {
            if (heights[j++] != i) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {1,1,4,2,1,3};
    auto ret = heightChecker(nums);
    cout << ret << " ";
    return 0;
}