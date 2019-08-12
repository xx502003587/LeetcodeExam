/*
 * 题目：
 * 输入一个链表，输出该链表中倒数第k个结点。
 *
 * 思路：
 * 1. 遍历两次链表，第一次计算链表长度n，第二次输出第 n-k+1 个结点
 * 2. 遍历一次链表，快慢指针法————令快慢指针同时指向头结点，然后快指针先前进到第k个结点，
 * 然后快慢指针同步移动，当快指针到达最后一个结点时，慢指针指向的正是倒数第k个结点。
 * 
 * 快指针前进过程中要注意判空，即k大于链表长度的情况
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == NULL || k == 0) {
        return NULL;
    }
    ListNode* fast = pListHead;
    ListNode* slow = pListHead;
    // 先让快指针到达第k个结点
    for (int i = 1; i < k; i++) {
        if (fast->next != NULL) {
            fast = fast->next;
        } else {
            return NULL;
        }

    }
    // 同步移动直到fast指向最后一个节点
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
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

    auto ret = FindKthToTail(head, 5);
    cout << ret->val << endl;
    return 0;

}
