/*
 * 题意：
 * 有n个箱子，每个箱子上有一个数；有m把钥匙，每把钥匙上有一个数
 * 只有箱子的数和钥匙的数和为奇数时，该钥匙才可以打开该锁
 * 一个锁只能被开一次，一把钥匙只能使用一次，问最多可以打开多少个箱子？
 * 
 * 思路：
 * 只有奇数和偶数相加才能得到奇数
 * 如果A数组中奇数有A1个，偶数有A2个，B数组中奇数有B1个，偶数有B2个
 * 那么A1和B2两个数中小的那一个决定了可以配对出min(A1,B2)个奇数
 * A2和B1两个数中小的那一个决定了可以配对出min(A2,B1)个奇数
 * 相加的和即为最多能配对出多少个奇数
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> box(n,0);
    int box_even = 0, box_odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
        if (box[i] % 2 == 0) {
            ++box_even;
        } else {
            ++box_odd;
        }
    }

    vector<int> key(m,0);
    int key_even = 0, key_odd = 0;
    for (int i = 0; i < m; i++) {
        cin >> key[i];
        if (key[i] % 2 == 0) {
            ++key_even;
        } else {
            ++key_odd;
        }
    }
    cout << min(box_even, key_odd) + min(key_even, box_odd);
    return 0;
}