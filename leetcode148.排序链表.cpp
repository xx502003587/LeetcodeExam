/*
 * 题意：
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *
 * 思路：
 * 归并排序，并且由于限制常数级空间复杂度，不能使用递归
 * 自底向上进行归并排序，从链表头开始不停地截断两个 size=1 的链表，然后进行归并
 * 一次结束后，每两个节点之间是有序的
 * 第二次从链表头开始不停地截断两个 size*2=2 的链表，然后进行归并
 * 一次结束后，每4个结点之间是有序的
 * 一直进行到 size 大于链表长度为止即可
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

// cut 方法表示：从 head 结点开始，截断一个长度为 n 的链表，然后返回后半部分的链表头结点
ListNode* cut(ListNode* head, int n) {
    auto p = head;
    // while 循环结束后，p 往后移动了 n-1 步
    while (--n && p) {
        p = p->next;
    }
    // 如果 p 为空，表明从 head 开始的链表不足以构成一个长度为 n 的链表，所以后半部分的链表头结点肯定是 null
    if (!p) {
        return nullptr;
    }
    // next 指向后半部分的链表头结点
    auto next = p->next;
    // 截断两个链表
    p->next = nullptr;
    return next;
}

// merge 方法表示 二路归并
ListNode* merge(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto p = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        } else {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    p->next = l1 ? l1 : l2;
    return head->next;
}

ListNode* sortList(ListNode* head) {
    // 使用一个临时节点指向头结点
    auto th = new ListNode(0);
    th->next = head;
    auto p = head;
    int length = 0;
    // 计算链表的长度
    while (p) {
        ++length;
        p = p->next;
    }

    // size 表示每次截断链表的长度，因为每次归并后子链表的长度都是2的幂，所以每次更新都左移一位
    for (int size = 1; size < length; size <<= 1) {
        auto cur = th->next;
        // tail 总是指向已经归并好的链表的尾结点
        auto tail = th;

        while (cur) {
            // left 表示截断的第一个子链表的头结点
            auto left = cur;
            // right 表示截断的第二个子链表的头结点
            auto right = cut(left, size);
            // cur 指向第二个子链表截断后 后半部分的头结点
            cur = cut(right, size);
            // 将两个子链表进行归并
            tail->next = merge(left, right);
            while (tail->next) {
                tail = tail->next;
            }
        }
    }
    return th->next;
}

int main() {
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(7);
    ListNode* node5 = new ListNode(8);
    ListNode* node6 = new ListNode(9);
    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(11);
    ListNode* node9 = new ListNode(5);
    ListNode* node10 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    auto ret = sortList(node1);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
