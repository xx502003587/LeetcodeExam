/*
 * 题意：
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 * 思路：
 * 使用两个指针，一个指针保存值比 x 小的节点，另一个保存值比 x 大的节点，然后合并
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    auto p1 = new ListNode(-1);
    auto cur1 = p1;
    auto p2 = new ListNode(-1);
    auto cur2 = p2;

    while (head) {
        if (head->val < x) {
            cur1->next = head;
            cur1 = cur1->next;
        } else {
            cur2->next = head;
            cur2 = cur2->next;
        }
        head = head->next;
    }
    cur1->next = p2->next;
    cur2->next = nullptr;
    return p1->next;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    auto p = partition(node1, 3);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
