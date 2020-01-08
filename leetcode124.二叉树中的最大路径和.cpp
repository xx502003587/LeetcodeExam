/*
 * 题意：
 * 给定一个非空二叉树，返回其最大路径和。
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_gain(TreeNode* node, int& max_sum) {
    if (!node) {
        return 0;
    }
    int left_gain = max(max_gain(node->left, max_sum), 0);
    int right_gain = max(max_gain(node->right, max_sum), 0);

    int price = node->val + left_gain + right_gain;
    max_sum = max(price, max_sum);

    return node->val + max(left_gain, right_gain);
}

int maxPathSum(TreeNode* root) {
    int max_sum = INT_MIN;
    max_gain(root, max_sum);
    return max_sum;
}

int main() {
    auto node1 = new TreeNode(-10);
    auto node2 = new TreeNode(9);
    auto node3 = new TreeNode(20);
    auto node4 = new TreeNode(15);
    auto node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    auto ret = maxPathSum(node1);

    cout << ret << endl; // 42
    return 0;
}
