/*
 * 题意：
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 示例 : 给定这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 *
 * 思路：
 * 每遍历k个结点，记录待反转部分的前一个和后一个，反转后拼接
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

ListNode* ReverseList(ListNode* pHead) {
    if (pHead == NULL) {
        return NULL;
    }
    ListNode* pre = NULL;
    ListNode* cur = pHead;
    ListNode* fast = cur;
    while (cur) {
        fast = cur->next;
        cur->next = pre;
        pre = cur;
        cur = fast;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto pre = dummy;
    auto end = dummy;

    while (end->next) {
        for (int i = 0; i < k && end; ++i) {
            end = end->next;
        }
        if (!end) {
            break;
        }
        auto start = pre->next;
        auto next = end->next;
        end->next = nullptr;
        pre->next = ReverseList(start);
        start->next = next;

        pre = start;
        end = pre;
    }
    return dummy->next;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    ListNode* node9 = new ListNode(9);
    ListNode* node10 = new ListNode(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    auto p = reverseKGroup(node1, 3);

    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
