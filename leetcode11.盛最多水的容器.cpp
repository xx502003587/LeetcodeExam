/*
 * 题意：
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 思路：
 * 容纳的水量其实是一个矩形的面积，垂线段的高度是矩形的一条边，两条垂线段之间的距离是矩形的另一条边
 * 根据木桶原理，盛水量的多少是由两个垂线段中较矮的那一个决定的
 * 使用双指针法，左指针指向最左端的垂线段 i ，右指针指向最右端的垂线段 j 
 * 那么 面积 = 垂线段之间的距离 (j - i) * 垂线段之中矮的那一条的高度 min(i, j)
 * 接下来，考虑移动指针
 * 如果将高的那一个指针向中间移动，那么 (j-i) 会变小，min(i,j) 也不会变大，面积不会增大
 * 所以要考虑将矮的那一个指针向中间移动，这样一来，虽然  (j-i) 会变小，但是 min(i,j) 有可能会变大，从而使面积增大
 * 过程中维护更新全局最大面积即可。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int area = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        area = max(area, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    auto ret = maxArea(height);
    cout << ret << " "; // 49
    return 0;
}
