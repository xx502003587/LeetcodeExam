/*
 * 题意：
 * 给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。
 * 换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦）
 * （删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。
 * 注意，删除一个元素后，子数组 不能为空。
 *
 * 思路：
 * 
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximumSum(vector<int>& arr) {
    vector<long> f(arr.size(), 0);
    vector<long> g(arr.size(), 0);

    f[0] = arr[0];
    g[0] = INT_MIN;

    for (auto i = 1; i < arr.size(); ++i) {
        f[i] = max(f[i-1]+arr[i], static_cast<long>(arr[i]));
        g[i] = max(g[i-1]+arr[i], f[i-1]);
    }

    long res = INT_MIN;
    for (auto i = 0; i < arr.size(); ++i) {
        res = max(res, max(f[i], g[i]));
    }
    return res;
}

int main() {
    vector<int> arr = {1,-2,0,3};
    auto ret = maximumSum(arr);
    cout << ret << endl;
    return 0;
}