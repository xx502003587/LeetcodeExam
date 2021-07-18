/*
 * 题意：
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”
 * 
 * 思路：
 * 从"反转单词顺序"的思路来推理
 * 将"hello world"反转之后得到"world hello"，可以看做将hello左移5个位置的结果
 * 把字符串分成两个部分，一部分是前面需要左移的一段，一部分是后面的一段
 * 先将两个部分分别进行逆序，然后再对整个字符串逆序，就可以达到所要求的结果
 * 如题意中的示例：分别逆序后得到cbafedZYX，再整个逆序得到XYZdefabc
 */

#include <iostream>
#include <string>

using namespace std;

void reverse(string& str, int left, int right) {
    while (left < right) {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        ++left;
        --right;
    }
}

string LeftRotateString(string str, int n) {
    if (str.empty()) {
        return str;
    }
    if (n == 0 || n == str.length()) {
        return str;
    }
    reverse(str, 0, n - 1);
    reverse(str, n, str.length() - 1);
    reverse(str, 0, str.length() - 1);
    return str;
}

int main() {
    string str = "abcXYZdef";
    auto ret = LeftRotateString(str, 3); // XYZdefabc
    cout << ret << endl;
    return 0;
}
