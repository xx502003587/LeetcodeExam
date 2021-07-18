/*
 * 题意：
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 1. 每个孩子至少分配到 1 个糖果
 * 2. 相邻的孩子中，评分高的孩子必须获得更多的糖果
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 * 思路：
 * 维护两个数组 left 和 right
 * left[i] 数组表示：如果学生 i 比他左边的学生 i-1 分数高，那么他应该比他左边的学生分到的糖果多，即 left[i] = left[i-1] + 1
 * right 数组表示：如果某个学生 i 比他右边的学生 i+1 分数高，那么他应该比他右边的学生分到的糖果多，即 right[i] = right[i+1] + 1
 * 为了满足题目要求，某个学生应该获得的糖果数应该是 max(left[i], right[i])
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    int len = ratings.size();

    vector<int> left(len, 1);
    for (int i = 1; i < len; ++i) {
        // 比左边的分数高，就应该比左边的多拿糖果
        if (ratings[i] > ratings[i-1]) {
            left[i] = left[i-1] + 1;
        }
    }

    vector<int> right(len, 1);
    for (int i = len - 2; i >= 0; --i) {
        // 比右边的分数高，就应该比右边的多拿糖果
        if (ratings[i] > ratings[i+1]) {
            right[i] = right[i+1] + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < len; ++i) {
        // 某同学应该获得的糖果应该是两者中较大的一个
        sum += max(left[i], right[i]);
    }
    return sum;
}

int main() {
    vector<int> ratings = {1,2,2};
    auto ret = candy(ratings); // 4
    cout << ret;
    return 0;
}
