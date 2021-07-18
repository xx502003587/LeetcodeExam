/*
 * 题意：
 * 给定一个二叉树，返回它的中序遍历序列。
 *
 * 思路：
 *
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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) {
        return ret;
    }
    stack<TreeNode*> s;
    auto p = root;
    while (!s.empty() || p) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            ret.push_back(p->val);
            p = p->right;
        }
    }
    return ret;
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

    auto ret = inorderTraversal(node1); // 6 4 7 2 5 1 3 
    for (auto item : ret) {
        cout << item << " ";
    }

    return 0;
}