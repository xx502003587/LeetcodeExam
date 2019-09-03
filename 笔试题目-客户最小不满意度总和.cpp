/*
 * 题意：
 * 一个队伍中有n个顾客，从1到n标号，一开始每个顾客i在队伍中的位置是i。
 * 每个顾客有两个属性ai和bj。每个顾客的不满意度等于他前面的人数与ai相乘，加上他后面的人数与bj相乘。
 * 正式来说，假设某个顾客位于位置j，那么他的不满意度就等于ai * (j-1) + bj * (n-j)
 * 作为咖啡店的经理，本着顾客至上的原则，需要重新安排顾客的顺序，使得所有顾客的不满意度总和最小。
 *
 * 思路：
 * 对单个顾客的不满意度公式做数学变换，为了方便表示，将 ai 和 bj 用 a 和 b 替换
 * a * (j-1) + b * (n-j) = a*j - a + b*n - b*j = (a-b) * j + b*n - a
 * 要想让不满意度总和最小，需要保证每个不满意度都最小
 * 上述公式表示一个顾客的不满意度：其中(a-b) * j是变量，与该顾客的位置有关；而b*n - a是定值
 * 想让该表达式最小，只需要让 (a-b)*j 值最小即可
 * 因为j是递增的，所以只要将所有顾客的 a-b 值进行降序排列，就可以保证所有顾客的 (a-b)*j 值最小（大数乘以小数+小数乘以大数  总和要比  小数乘以小数+大数乘以大数  小）
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(const int& a, const int& b) {
    if (a > b) {
        return true;
    }
    return false;
}

int main() {
    int n = 0;
    cin >> n;
    vector<long long> a_b;

    long long res = 0;
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        // 记录 a-b 的值用以排序
        a_b.push_back(a - b);
        // 把每个顾客的定值计算出来
        res += (b * n - a);
    }
    // 降序排序
    sort(a_b.begin(), a_b.end(), func);

    for (int i = 0; i < n; i++) {
        // 计算变值部分
        res += (a_b[i] * (i+1));
    }

    cout << res << endl;
    return 0;
}