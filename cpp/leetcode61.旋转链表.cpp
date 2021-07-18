/*
 * 题意：
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 如：1->2->3->4->5->NULL, k = 2 应该输出 4->5->1->2->3->NULL
 *
 * 思路：
 * 首先将链表连成一个环，然后从原始的表头往后移动 (n-k-1) 步，断开即可，其中 n 是链表长度
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    int length = 0;
    auto p = head;
    // 计算链表的长度，由于while循环条件设置的是 p->next 不空
    // 所以循环结束后 p 指向的是链表的最后一个节点，得到的 length 为（总长度-1）
    while (p->next) {
        ++length;
        p = p->next;
    }
    length++;
    // 先将链表连成环
    p->next = head;
    // 将k对长度取余，以免造成 k 大于 length 的情况
    k %= length;
    // 计算需要断链的位置
    int steps = length - k;
    p = head;
    // 从原始的头结点往后走 length-k-1 步
    for (int i = 0; i < steps - 1; ++i) {
        p = p->next;
    }
    // 得到应该断链处的下一个节点，这个节点是断链后的链表头结点
    auto next = p->next;
    // 断链
    p->next = nullptr;
    return next;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto ret = rotateRight(node1, 7);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
