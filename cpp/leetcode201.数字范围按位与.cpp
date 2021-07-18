/*
 * 如果数字m != n，则在m, n范围内的数的最后一位必然同时存在1和0，因此最后一位的按位与&的结果必为0。
 * 所以m,n范围内的数的按位与的结果就是各个数的各位对齐后高位共同数字串末尾全补0的值
 */

#include <iostream>

using namespace std;


int rangeBitwiseAnd(int m, int n) {
    int count = 0;
    while (n != m) {
        n >>= 1;
        m >>= 1;
        count++;
    }
    return (m << count);
}

int main() {
    auto ret = rangeBitwiseAnd(5,7);
    cout << ret << endl;
    return 0;
}
