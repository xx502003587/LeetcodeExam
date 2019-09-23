/*
 * 题意：
 * 给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得：
 * left 中的每个元素都小于或等于 right 中的每个元素。
 * left 和 right 都是非空的。
 * left 要尽可能小。
 * 在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。
 *
 * 思路：
 * 两个子数组需要满足的主要条件为：left 的每个元素小于等于 right 的每个元素
 * 数组中一定存在多个元素，使得该元素左边的数都比该元素以及其右边的数小
 * 那么只需要找出两个数组，使得左边子数组的最大值比右边子数组的最小值小即可
 * 为了保证 left尽可能小 这个条件，选择上述多个元素中最左边的那个元素即可
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partitionDisjoint(vector<int>& A) {
    int len = A.size();
    vector<int> left_max(len, 0);
    left_max[0] = A[0];
    // 从左向右 记录包括位置 i 在内的 i 左边的元素中的最大值
    for (int i = 1; i < len; ++i) {
        left_max[i] = max(left_max[i-1], A[i]);
    }

    vector<int> right_min(len, 0);
    right_min[len-1] = A[len-1];
    // 从右向左 记录包括位置 i 在内的 i 右边的元素中的最小值
    for (int i = len-2; i >= 0; --i) {
        right_min[i] = min(right_min[i+1], A[i]);
    }

    for (int i = 1; i < len; ++i) {
        // 当第一次出现 left中的最大值 小于等于 right中的最小值时，返回当前位置
        if (left_max[i-1] <= right_min[i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    vector<int> A = {5,0,3,8,6};
    auto ret = partitionDisjoint(A);
    cout << ret << " "; // 3
    return 0;
}
