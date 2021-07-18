/*
 * 题意：
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * 思路：
 * 考虑木桶原理（短板效应）
 * 一个位置能接雨水的数量，应该取决于它左右两边最高的两个板子中较矮的那个板子的高度，用这个高度减去当前位置的高度所得到的结果就是该位置可以存储的雨水数量
 * 为了避免每遍历到一个位置时都向左向右寻找最高的板子高度从而增加一层复杂度，可以预先将每个位置左右两边的最高板子高度记录下来
 * 那么能接到雨水的总量就是 每个位置左右两边最高的板子中较矮的一个减去当前高度求和
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int> &height) {
    if (height.empty()) {
        return 0;
    }
    int len = height.size();

    // 记录每个位置左边的最高高度
    vector<int> left(len, 0);
    left[0] = height[0];
    for (int i = 1; i < len; i++) {
        left[i] = max(height[i], left[i - 1]);
    }
    // 记录每个位置右边的最高高度
    vector<int> right(len, 0);
    right[len - 1] = height[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        right[i] = max(height[i], right[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < len; ++i) {
        // 两个最高高度中较矮的一个减去当前高度就是当前位置可以接雨水的量
        res += min(left[i], right[i]) - height[i];
    }
    return res;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto ret = trap(height);
    cout << ret << " ";
    return 0;
}
