/*
 * 题意：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 *
 * 思路：
 * 二叉搜索树的中序遍历序列是一个的递增序列，可以利用这一点来解题
 * 在二叉搜索树中，左子节点的值总是小于父节点的值，右子节点的值总是大于父节点的值，
 * 因此转换成双向链表后，原先指向左子节点的指针应该指向链表中的前一个节点，原先指向右子节点的指针应该指向链表中的后一个节点
 * 当遍历到某个节点时，根据排序链表的定义，它应该和它左子树中值最大的那个节点连接起来，同时和它右子树中值最小的那个节点连接起来
 * 使用递归思想来解决：令一个指针pre永远指向已经转换好的排序链表的最后一个节点，每当遍历到一个结点时，它的左子树已经转换完成，只需将当前节点的左指针指向pre节点，将pre结点的右指针指向当前节点，就完成了把当前节点插入排序链表中的步骤
 * 然后再将pre指向当前节点，遍历右子树即可。
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void ConvertNode(TreeNode* root, TreeNode*& pre) {
    if (!root) {
        return;
    }
    TreeNode* cur = root;
    // 中序遍历首先要找到最左下角的节点
    if (cur->left != NULL) {
        ConvertNode(cur->left, pre);
    }

    // 另当前节点的左指针指向pre
    cur->left = pre;
    // 如果pre节点不空，将pre节点的右指针指向当前节点
    if (pre != NULL) {
        pre->right = cur;
    }
    // 当前节点已经被加入到排序链表中，将pre修改为当前节点
    pre = cur;
    // 遍历右子树
    if (root->right != NULL) {
        ConvertNode(cur->right, pre);
    }
}

TreeNode* Convert(TreeNode* pRootOfTree) {
    TreeNode* pre = NULL;
    // 将二叉搜索树转换为排序链表
    ConvertNode(pRootOfTree, pre);
    // 因为上述步骤返回的指针指向的是排序链表的最后一个节点，所以要找到第一个节点并返回
    TreeNode* head = pre;
    while (head != NULL && head->left != NULL) {
        head = head->left;
    }
    return head;
}

int main() {
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(14);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(8);
    TreeNode* node6 = new TreeNode(12);
    TreeNode* node7 = new TreeNode(16);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    auto ret = Convert(node1);
    
    while (ret && ret->right) {
        cout << ret->val << " ";
        ret = ret->right;
    }
    return 0;
}
