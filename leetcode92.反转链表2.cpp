/*
 * 题意：
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 说明：
 * 1 ≤ m ≤ n ≤ 链表长度。
 *
 * 思路：
 * 找到 m到n 区间的子链表，断开后进行反转，然后将头尾接起来即可
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

// 反转单链表
ListNode* reverse(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* fast = cur;
    while (cur) {
        fast = cur->next;
        cur->next = pre;
        pre = cur;
        cur = fast;
    }
    return pre;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto cur = dummy;

    // 找到开始反转节点的前一个节点
    for (int i = 0; i < m - 1; ++i) {
        cur = cur->next;
    }
    // 将该节点记录下来，后续会用于拼接新链表
    auto pre = cur;
    // 继续向后找到待反转链表部分的最后一个节点
    for (int i = 0; i < n-m+1; ++i) {
        cur = cur->next;
    }
    // 将该节点的下一个节点记录下来，后续会用于拼接新链表
    auto head2 = cur->next;
    // 断链
    cur->next = nullptr;

    // 记录下待反转链表的头结点，反转完毕后就是尾结点，用于拼接原链表中后续的节点
    auto tmp = pre->next;
    // 待反转链表进行反转，得到新的头结点
    auto newHead = reverse(pre->next);
    // 拼接头尾节点
    pre->next = newHead;
    tmp->next = head2;
    return dummy->next;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto p = reverseBetween(node1, 2,4);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
