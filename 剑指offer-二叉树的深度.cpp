/*
 * 题意：
 * 输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
 *
 * 思路：
 * 对于一个节点来说，以它为根节点的子树深度应该是其左子树和右子树深度较大的那个+1（当前节点算一层）
 * 根据该思路递归即可
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int TreeDepth(TreeNode* pRoot) {
    // 空节点返回深度为0
    if (!pRoot) {
        return 0;
    }
    // 左右子树深度较大的值+1即为 以当前节点为根节点的树的深度
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
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

    auto ret = TreeDepth(node1);
    cout << ret << endl; // 4
    return 0;
}
