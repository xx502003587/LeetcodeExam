/*
 *
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
