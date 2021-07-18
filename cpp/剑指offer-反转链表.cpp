/*
 * 题目：
 * 输入一个链表，反转链表后，输出新链表的表头。
 *
 * 思路：
 * 三指针法，前一个 当前 下一个
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
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

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    auto ret = ReverseList(head);

    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
