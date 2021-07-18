/*
 * 题意：
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 思路：
 * 使用快慢指针
 * 用一个哑节点做链表的表头，令慢指针指向哑结点，快指针指向哑结点的下一个节点
 * 快指针用来跳过值重复的节点，慢指针用来拼接快指针
 * 从哑结点到慢指针之间的链表总是符合题目要求的
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

ListNode *deleteDuplicates(ListNode *head) {
    auto dummy = new ListNode(-1);
    dummy->next = head;
    auto slow = dummy;
    auto fast = dummy->next;

    // 如果 fast 不空就循环
    while (fast) {
        // 当 fast 的下一个节点不空 并且 两个节点的值相同时，记录下这个值，并且用 fast 跳过后面值相同的节点
        if (fast->next && fast->val == fast->next->val) {
            int tmp = fast->val;
            while (fast && fast->val == tmp) {
                auto del = fast;
                fast = fast->next;
                delete del;
                del = nullptr;
            }
        }
        // 不满足上述条件时，令 slow 的下一个指向 fast，然后更新 slow 和 fast 的位置
        else {
            slow->next = fast;
            slow = fast;
            fast = fast->next;
        }
    }
    slow->next = fast;
    return dummy->next;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(3);
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
