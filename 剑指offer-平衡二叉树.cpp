/*
 * 题意：
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *
 * 思路：
 * 1. 根据计算二叉树深度的办法，对每个节点进行判断，如果每个节点左右深度差的绝对值 <= 1，则是平衡二叉树
 * （缺点：重复遍历节点多次）
 * 2. 后序遍历的方法（每个节点遍历一次）
 * 如果用后序遍历的方法来遍历二叉树的每一个结点，可以发现当遍历到一个节点之前就已经遍历了它的左右子树。
 * 所以只需要在遍历左右子树时记录它的深度，就可以一边遍历一边判断当前节点是否平衡
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

bool check(TreeNode* root, int& depth) {
    // 空节点返回true，并且标记深度为0
    if (!root) {
        depth = 0;
        return true;
    }
    int left, right;
    // 如果左右都平衡，则计算当前节点是否平衡
    if (check(root->left, left) && check(root->right, right)) {
        int dif = left - right;
        if (dif >= -1 && dif <= 1) {
            depth = max(left, right) + 1;
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if (!pRoot) {
        return true;
    }
    int depth = 0;
    return check(pRoot, depth);
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

    auto ret = IsBalanced_Solution(node1);
    cout << ret << endl; // 0

    node3->left = node6;
    node3->right = node7;

    ret = IsBalanced_Solution(node1);
    cout << ret << endl; // 1

    return 0;
}
