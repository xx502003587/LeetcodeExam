/*
 * 题意：
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 *
 * 思路：
 * 如果是一个整型数组里除了一个数字之外，其他的数字都出现了两次，那么将所有数进行异或，最后得到的结果就是那个单独的数。
 * 对于本题来说，如果可以把整个数组分成两个部分，把这两个数分到两个部分中去，对于任一部分来讲都满足上述情况，那么在两个部分中进行异或得到的两个数就是要求的两个数
 * 所以本题的关键在于如何将数组划分成两个部分
 * 
 * 考虑将所有的数先进行一次异或，最后得到的结果是这两个不同的数的异或结果
 * 因为这两个数不相同，所以异或结果中必定有一个位是1（即这两个数必定有一个位上面对应的数不同）
 * 找出这个异或结果中最右边的1所在的位置，根据这个位置可以将数组划分成两个部分
 * 因为这两个数在这一位上不相同，所以这两个数肯定被划分到两个部分中去
 * 其他的数因为都是成对的，所以也会成对地被划分到某个部分中去
 * 最后对这两个数组分别异或，就得到了两个结果
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int>& nums) {
    int xorsum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        xorsum = xorsum ^ nums[i];
    }
    int index = 0;
    while (xorsum) {
        if ((xorsum >> index) & 1) {
            break;
        } else {
            index++;
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i]>>index) & 1) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }
    return vector<int>{a,b};
}

int main() {
    vector<int> input = {2,4,3,6,3,2,5,5};
    auto ret = FindNumsAppearOnce(input);
    for (auto num : ret) {
        cout << num << endl; // 4 6
    }
    return 0;
}
