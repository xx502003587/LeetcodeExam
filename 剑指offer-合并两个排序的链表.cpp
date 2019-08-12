/*
 * 题目：
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 *
 * 思路：
 * 创建一个头指针h，用两个指针p1 p2分别指向两个链表的头部，当p1 p2都不为空时，每次判断p1 p2所指向节点的数值大小，将值较小的节点接到h的next，并将值较小的指针和h后移
 * 当p1 p2其中一个指针为空时，表明一个链表已经遍历完毕，只需将另一个指针直接接在h后即可
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    // 都空时，返回空
    if (!pHead1 && !pHead2) {
        return NULL;
    } 
    // 一个空一个不空时，返回不空的那个链表
    else if (!pHead1) {
        return pHead2;
    } else if (!pHead2) {
        return pHead1;
    }
    ListNode* h = new ListNode(0);
    auto ret = h;
    auto p1 = pHead1;
    auto p2 = pHead2;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            h->next = p1;
            p1 = p1->next;
            h = h->next;
        } else {
            h->next = p2;
            p2 = p2->next;
            h = h->next;
        }
    }
    if (!p1) {
        h->next = p2;
    } else if (!p2) {
        h->next = p1;
    }
    return ret->next;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;

    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(6);

    node4->next = node5;
    node5->next = node6;

    auto ret = Merge(node1, node4);

    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
