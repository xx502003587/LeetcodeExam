/*
 * 题意：
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 思路：
 * 二叉搜索树的中序序列应该是一个非递减的序列，可以利用该特性解题
 * 对树进行中序遍历，每次遍历到一个节点时，判断该节点的值与遍历的前一个节点的值
 * 该节点的值如果小于前一个节点的值，表明树不是二叉搜索树
 * 该节点的值如果大于等于前一个节点的值，表明符合条件，保存当前节点的值，用作遍历到下一个节点与其作比较
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root) {
    if (!root) {
        return true;
    }
    stack<TreeNode*> s;
    auto p = root;
    // 遍历第一个节点时，之前并没有节点，所以将之前节点的值初始化为最小值
    long pre = -LONG_MAX;
    while (!s.empty() || p) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            // 如果当前值小于等于前一个节点的值，表明序列不是非递减的
            if (p->val <= pre) {
                return false;
            }
            // 保存当前节点的值，用作下一个节点进行比较
            pre = p->val;
            p = p->right;
        }
    }
    return true;
}

int main() {
    auto node1 = new TreeNode(1);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    auto node4 = new TreeNode(4);
    auto node5 = new TreeNode(5);
    auto node6 = new TreeNode(6);
    auto node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node4->left = node6;
    node4->right = node7;

    auto ret = isValidBST(node1); // 6 4 7 2 5 1 3
    cout << ret << " ";

    return 0;
}