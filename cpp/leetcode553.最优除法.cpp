/*
 * 题意：
 * 给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。
 * 但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。
 * 你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。
 * 你的表达式不应该含有冗余的括号。
 *
 * 思路：
 * 观察数组可以发现，无论怎么加括号，第一个数永远是作为被除数存在的，而第二个数永远作为除数存在
 * 所以要想让结果最大，只需要让被除数变大，或者让除数变小即可
 * 此题中考虑将除数变小，想要让除数变到最小的情况，只需要给除数一直做除法即可
 * 所以此题中的括号位置都是固定死的，即从第二个数开始全部括起来
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string optimalDivision(vector<int>& nums) {
    int len = nums.size();
    if (!len) {
        return "";
    } else if (len == 1) {
        return to_string(nums[0]);
    } else if (len == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string part1 = to_string(nums[0]) + "/";
    string part2 = to_string(nums[1]);
    for (int i = 2; i < len; ++i) {
        part2 += "/" + to_string(nums[i]);
    }
    return part1 + "(" + part2 + ")";
}

int main() {
    vector<int> nums = {1000,100,10,2};
    cout << optimalDivision(nums);
    return 0;
}
