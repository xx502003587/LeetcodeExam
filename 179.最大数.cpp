/*
 * 为了构建最大的数，高位的数肯定越大越好
 * 将整数转换为字符串之后，直接对字符串进行降序排序
 * 对于长度相同的字符串，会从左到右对比逐个字符的ASCII码大小，直到出现不同的字符为止
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 自定义排序过程，将两个整数转为字符串，对比a+b和b+a的大小
string largestNumber(vector<int>& nums) {
    // 自定义的排序返回值表示 第一个参数是否应该在第二个参数之前
    // 所以当传入3和30时，"330" > "303"，于是返回true，表明3大于30
    sort(nums.begin(), nums.end(), [](int a, int b) {
        auto aa = to_string(a);
        auto bb = to_string(b);
        return aa + bb > bb + aa; 
    });
    // 排序后如果最大数为0 则所有数都为0 返回0即可
    if (nums[0] == 0) {
        return "0";
    }

    string ret;
    // 将排序后的数 逐个拼接起来就是最大的数
    // 9534330
    for (auto num : nums) {
        ret.append(to_string(num));
    }
    return ret;
}

int main() {
    vector<int> nums = {3,30,34,5,9};
    auto ret = largestNumber(nums);
    cout << ret << endl;

    return 0;
}
