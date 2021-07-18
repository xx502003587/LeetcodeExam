/*
 * 题意：
 * 有
 *
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void func(vector<unsigned long long>& help, int position, unsigned long long& pre, unsigned long long& sum) {
    if (position == 0) {
        return;
    }
    auto cur = help[position] + pre;
    sum += cur;
    pre = cur;
    func(help, position-1, pre, sum);
}

int main() {
    int m = 0, last = 0;
    cin >> m >> last;
    if (m >= 100 || last < 1) {
        cout << 0;
        return 0;
    }

    vector<unsigned long long> help(m, 0);
    help[0] = 2;
    int n = 1;
    unsigned long long cnt = 1;
    for (int i = 1; i < m; ++i) {
        help[i] = cnt + 1;
        cnt *= ++n;
    }
    unsigned long long sum = last;
    unsigned long long pre = last;
    func(help, m-1, pre, sum);

    cout << sum;
    return 0;
}
