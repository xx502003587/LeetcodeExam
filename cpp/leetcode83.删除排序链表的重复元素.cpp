/*
 * 题意：
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 思路：
 * 链表基本操作
 * 当前节点和下一个节点都不为空的时候，判断两个节点的值
 * 如果值相等，就令当前节点指向下一个节点的下一个节点，然后把下一个节点释放掉
 * 如果不相等，令当前节点向前走一步即可
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

ListNode* deleteDuplicates(ListNode* head) {
    auto cur = head;

    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            auto tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            tmp = nullptr;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto p = deleteDuplicates(node1);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
