/*
 * 题意：
 * 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 *
 * 思路：
 * 从根节点开始，将target减去当前节点的值并传递给子树，这是一个子问题，可以使用递归方法解决。
 * 那么从根节点到叶子节点的计算过程中，每次用传递给当前节点的target减去当前节点的值并递归到子树上
 * 如果存在一条路径使得和为target，那么从根节点到某个叶子节点时，传递到叶子节点的值应该为0，此时就构成了一条路径，加入结果集即可
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, vector<vector<int>>& ret, vector<int>& tmp, int sum) {
    if (!root) {
        return;
    }
    // 计算减去当前节点的值之后还剩下多少
    sum -= root->val;
    tmp.push_back(root->val);
    // 如果当前节点是叶子节点并且刚好剩下的sum == 0，表示当前路径为有效路径，直接加入结果集即可
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) {
            ret.push_back(tmp);
        }
    } 
    // 否则递归子树
    else {
        helper(root->left, ret, tmp, sum);
        helper(root->right, ret, tmp, sum);
    }
    tmp.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> ret;
    if (!root) {
        return ret;
    }
    vector<int> tmp;
    helper(root, ret, tmp, expectNumber);
    return ret;
}

int main() {
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(12);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;

    auto ret = FindPath(node1, 22);

    cout << "共找到" << ret.size() << "条路径" << endl;
    for (auto item : ret) {
        for (auto num : item) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}