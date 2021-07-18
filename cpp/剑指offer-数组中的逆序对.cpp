/*
 * 题意：
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。
 * 并将P对1000000007取模的结果输出。 即输出P%1000000007
 *
 * 思路：
 * 1. 时间复杂度为O(n^2)的解法
 * 遍历到每一个数时，将其与之后的每一个数作比较，累加对数
 * 
 * 2. 时间复杂度为O(nlogn)的解法
 * 利用归并排序进行解题
 * 考虑两个递增有序数组，如果前者的最大数比后者的最大数还大，那么前者的最大数比后者的所有数都大，所以前者的最大数所对应的逆序对数就是后者数组的长度
 * 根据这个思路，可以使用归并排序来把数组分为若干个子数组，在每个子数组中，用两个指针分别指向最后一个数
 * 如果第一个子数组中的数大于第二个子数组中的数，则构成逆序对，且数目等于第二个子数组中剩余数的个数。
 * 如果第一个子数组中的数小于第二个子数组中的数，则不构成逆序对。
 * 每一次比较的时候都把较大的数从后往前复制到一个辅助数组中去（相当于对两个子数组进行归并排序）
 */

#include <iostream>
#include <vector>

using namespace std;

long helper(vector<int>& data, vector<int>& copy, long left, long right) {
    if (left == right) {
        return 0;
    }
    long mid = left + (right - left) / 2;
    long leftcount = helper(data, copy, left, mid);
    long rightcount = helper(data, copy, mid+1, right);

    long i = mid;
    long j = right;
    long ix = right;
    long count = 0;
    while (i >= left && j > mid) {
        // 如果第一个子数组中的数大于第二个子数组中的数
        if (data[i] > data[j]) {
            // 把较大的数从后往前复制到一个辅助数组中去
            copy[ix--] = data[i--];
            // 数目等于第二个子数组中剩余数的个数
            count += j - mid;
        } else {
            copy[ix--] = data[j--];
        }
    }
    for (; i >= left; --i) {
        copy[ix--] = data[i];
    }
    for (; j > mid; --j) {
        copy[ix--] = data[j];
    }
    // 把区间内辅助数组的值拷贝给正式数组，以便进行下一轮迭代
    for (int k = left; k <= right; ++k) {
        data[k] = copy[k];
    }
    return (leftcount + rightcount + count) % 1000000007;
}

int InversePairs(vector<int> data) {
    if (data.size() <= 1) {
        return 0;
    }
    vector<int> copy(data.begin(), data.end());
    int count = helper(data, copy, 0, data.size() - 1);
    return count;
}

int main() {
    vector<int> input = {7, 5, 6, 4};
    auto ret = InversePairs(input);
    cout << ret << endl;

    return 0;
}
