/*
 * 题意：
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 *
 * 思路：
 * 例如 [5,7,6,9,11,10,8]，最后一个结点是8，也就是根节点，然后可以发现前三个数小于8，接下来三个数大于8
 * 于是8将前面六个数分为了两个序列，这是一个子问题，可以通过递归来解决
 * 每一次递归过程中，只需要判断序列是否一段连续的部分小于最后一个数，一段连续的部分大于最后一个数
 * 如果不是，直接返回false
 * 如果是，继续对分出来的两个区间递归子树
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check(vector<int>& sequence, int start, int end) {
    if (end <= start) {
        return true;
    }
    int i = start;
    // 找到第一个大于根节点数的下标
    for (; i < end; i++) {
        if (sequence[i] > sequence[end]) {
            break;
        }
    }
    int j = i;
    // 从这个下标开始如果都大于根节点数，表明该节点满足二叉搜索树的要求，继续递归子树
    // 如果有一个小于根节点数，就表明不满足要求，直接返回false
    for (; j < end; j++) {
        if (sequence[j] < sequence[end]) {
            return false;
        }
    }
    return check(sequence, start, i-1) && check(sequence, i, end-1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty()) {
        return false;
    }
    return check(sequence, 0, sequence.size()-1);
}

int main() {
    vector<int> positive = {5,7,6,9,11,10,8};
    cout << (VerifySquenceOfBST(positive) ? "YES" : "NO") << endl;
    vector<int> negative = {7,4,6,5};
    cout << (VerifySquenceOfBST(negative) ? "YES" : "NO") << endl;

    return 0;
}
