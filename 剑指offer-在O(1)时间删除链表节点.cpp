/*
 * 题目：
 * 给定单向链表的头指针和一个结点指针，在O(1)时间删除该结点
 *
 * 思路：
 * 如果要删除一个结点，必须得知道前一个结点的指针，然后将前一个结点的指针指向该结点的下一个结点，但是如果通过遍历来找到前一个节点，时间复杂度就是O(n)
 * 如果要在O(1)时间删除，只有一种办法：可以将下一个结点的值赋值给当前结点，即把当前节点变成下一个节点，然后将下一个节点删除。
 * 分三种情况：
 * 1. 如果要删除的节点不是尾结点，则直接将下一个节点的值赋值给当前节点，并指向下下一个结点，删除下一个节点即可
 * 2. 如果要删除的节点是尾结点，并且该链表不止一个结点，那么只能通过顺序查找的方式找到前一个节点然后删除当前节点
 * 3. 如果要删除的节点是尾结点，并且该链表只有一个结点，那么直接将该节点删除，将头指针置空即可
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void DeleteNode(ListNode*& head, ListNode* to_be_deleted) {
    // 如果删除的不是最后一个结点
    if (to_be_deleted->next != NULL) {
        auto nx = to_be_deleted->next;
        to_be_deleted->val = nx->val;
        to_be_deleted->next = nx->next;
        delete nx;
        nx = NULL;
    }
    // 如果删除的是最后一个结点 并且该链表就只有一个结点
    else if (head == to_be_deleted) {
        delete to_be_deleted;
        to_be_deleted = NULL;
        head = NULL;
    }
    else {
        auto tmp = head;
        while (tmp->next != to_be_deleted) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        delete to_be_deleted;
        to_be_deleted = NULL;
    }
}

void print_list(ListNode* iter) {
    while (iter) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // 测试删除中间的结点
    DeleteNode(head, node1);
    print_list(head);
    // 测试删除尾结点
    DeleteNode(head, node4);
    print_list(head);
    // 测试删除单一结点
    head->next = NULL;
    DeleteNode(head, head);
    print_list(head);
    return 0;
}
