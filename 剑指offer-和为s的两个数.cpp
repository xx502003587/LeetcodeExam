/*
 * 题意：
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 *
 * 思路：
 * 利用其有序的特性，双指针分别指向头和尾并向中间遍历
 * 如果两个指针指向的数的和刚好等于s，则根据乘积更新当前的结果
 * 如果和小于s，则表明下边界较小，将左指针右移一位
 * 如果和大于s，则表明上边界较大，将右指针左移一位
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int left = 0, right = array.size() - 1;
    pair<int, int> ret;
    bool found = false;
    int mul = INT_MAX;
    while (left < right) {
        int ts = array[left] + array[right];
        if (ts == sum) {
            if (array[left] * array[right] < mul) {
                mul = array[left] * array[right];
                ret.first = array[left];
                ret.second = array[right];
                found = true;
            }
            ++left;
            --right;
        } else if (ts < sum) {
            ++left;
        } else {
            --right;
        }
    }
    if (found)
        return vector<int>{ret.first, ret.second};
    else
        return vector<int>{};
}

int main() {
    vector<int> input = {1,2,4,7,8,11,15};
    auto ret = FindNumbersWithSum(input, 15);
    for (auto num : ret) {
        cout << num << " "; // 4 6
    }
    return 0;
}
