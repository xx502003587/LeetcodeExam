/*
 * 题意：
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
 * 如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
 * 你必须输出所有学生中的已知的朋友圈总数。
 *
 * 思路：
 * 1. DFS遍历
 * 遍历所有人，对每一个人，寻找他的好友，然后再找这个好友的好友，这样深度优先遍历下去
 * 设置一个标志数组记录某个人是否被寻找过，当一条关系链全部找完之后，这一个朋友圈里面的人就找全了
 * 
 * 2. 并查集
 * 一开始将所有人都看做自成一组，即共有n个朋友圈
 * 维护一个数组gp，gp[i]表示第i个人所属的组号
 * 每次遍历两个人，如果这两个人是朋友关系，根据gp[i]分别找到这两个人属于的组
 * 如果两个人属于不同的组，就将两个人合并（将一个人放到另一个人的组里去），然后将总组数减1
 * 最后剩下的组数就是朋友圈个数
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS
void dfs(vector<vector<int>> &M, vector<bool>& visit, int i) {
    // 记录当前人的状态为“已经遍历过”
    visit[i] = true;
    for (int j = 0; j < M.size(); ++j) {
        // 找到这个人的还没有遍历过的好友，进行深度遍历
        if (M[i][j] == 1 && !visit[j]) {
            dfs(M, visit, j);
        }
    }
}

int findCircleNum(vector<vector<int>> &M) {
    int pnum = M.size();
    int res = 0;
    // 记录每个人的遍历状态
    vector<bool> visit(pnum, false);
    for (int i = 0; i < pnum; ++i) {
        // 如果这个人没有被遍历过，就相当于找到了一个新的朋友圈
        if (!visit[i]) {
            ++res;
            // 深度遍历这个人的好友
            dfs(M, visit, i);
        }
    }
    return res;
}

// 并查集
int find(vector<int>& gp, int i) {
    // gp[i]的值的含义为 第i个人所属的组号
    // 如果第i个人自成一组，直接返回组号
    if (gp[i] == i) {
        return i;
    } 
    // 如果第i个人所属的组号是另一个号码，就去找到这个号码对应的那个人，返回这个号码
    else {
        int temp = find(gp, gp[i]);
        gp[i] = temp;
        return temp;
    }
    //return gp[i] == i ? i : find(gp, gp[i]);
}

int findCircleNum(vector<vector<int>> &M) {
    int pnum = M.size();
    // 初始组数为人数
    int group = pnum;

    vector<int> gp(pnum, 0);
    // 每个人自成一组
    for (int i = 0; i < pnum; ++i) {
        gp[i] = i;
    }

    for (int i = 0; i < pnum; i++) {
        for (int j = 0; j < pnum; j++) {
            // 两个不同的人是好友关系
            if (i != j && M[i][j] == 1) {
                // 找到两个人所属的组号
                int x1 = find(gp,i);
                int x2 = find(gp,j);
                // 组号不同就合并
                if (x1 != x2) {
                    gp[x1] = x2;
                    group--;
                }
            }
        }
    }
    return group;
}

int main() {
    vector<vector<int>> M = {{1, 1, 0},
                             {1, 1, 0},
                             {0, 0, 1}};
    cout << findCircleNum(M); // 2

    return 0;
}
