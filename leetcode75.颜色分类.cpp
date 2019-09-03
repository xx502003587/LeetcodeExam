/*
 * 题意：
 * 给出一个长度为n的整数数组，取值为0，1或2
 * 对数组进行原地排序，使得数组以0开始，中间是1，以2结束
 * 要求：使用常量空间，仅遍历数组一次
 *
 * 思路：
 * 1. 如果没有上述限制要求的话，一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，通过一次遍历计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 
 * 2. 使用三个指针p0, p2, cur来进行遍历
 * p0总是指向数组左侧所有的0的右边界，p2总是指向数组右边所有的2的左边界
 * 沿着数组移动cur指针：
 * 当cur指向的数是0，将cur指向的数和p0指向的数交换；当cur指向的数是2，将cur指向的数和p2指向的数交换
 */

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    if (nums.size() == 1) {
        return;
    }
    int p0 = 0, p2 = nums.size() - 1, cur = 0;
    while (cur <= p2) {
        // 交换第 curr 个和第 p0 个元素，并将指针都向右移
        if (nums[cur] == 0) {
            std::swap(nums[p0], nums[cur]);
            p0++;
            cur++;
        } 
        // 交换第 curr 个和第 p2 个元素，并将 p2指针左移 。
        else if (nums[cur] == 2) {
            std::swap(nums[p2], nums[cur]);
            p2--;
        } 
        // 将指针curr右移
        else {
            cur++;
        }
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for (auto item : nums) {
        cout << item << " ";
    }
    return 0;
}