/*
 * 题意：
 * 根据逆波兰表示法，求表达式的值。
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 * 思路：
 * 运算符在运算数后面的表达式就是逆波兰表达式
 * 例如 表达式 "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
 * 对应算数表达式为 ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * 因为每一个运算符都跟在该运算符所连接的两个运算数后面
 * 所以当发现一个运算符时，只需要将该运算符之前的两个数进行计算即可
 * 使用栈存储运算数
 * 遍历逆波兰表达式，当遍历到数时，直接压栈；当遍历到运算符时，从栈里面弹出两个操作数进行计算，将计算结果压栈
 * 直到遍历结束，栈顶元素就是最后的运算结果
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int compute(string oper, int a, int b) {
    int res = 0;
    if (oper == "+") {
        res = a + b;
    } else if (oper == "-") {
        res = a - b;
    } else if (oper == "*") {
        res = a * b;
    } else {
        res = a / b;
    }
    return res;
}

int str2num(string s) { //将string转换为int类型的函数，在之后要调用
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

int evalRPN(vector<string> &tokens) {
    stack<int> s;
    s.push(str2num(tokens[0]));

    for (int i = 1; i < tokens.size(); ++i) {
        string ch = tokens[i];
        // 如果是操作符，弹出两个数，并计算
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();
            // 需要注意，当做减法时，弹出的第一个数是减数，第二个数才是被减数
            s.push(compute(ch, top2, top1));
        }
        // 如果是操作数，就直接压栈
        else {
            s.push(str2num(tokens[i]));
        }
    }
    return s.top();
}

int main() {
    vector<string> input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    auto ret = evalRPN(input);
    cout << ret << endl; // 22

    return 0;
}