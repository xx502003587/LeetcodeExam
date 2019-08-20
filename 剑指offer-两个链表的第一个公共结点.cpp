/*
 * 题意：
 * 输入两个链表，找出它们的第一个公共结点。
 *
 * 思路：
 * 1. 利用两个辅助栈，分别将两个链表从头遍历并压入栈中
 * 每次比较两个栈的栈顶元素，如果相等则表示是公共结点，弹出并记录
 * 如果不相等则表明上一次弹出的是第一个公共结点
 * 
 * 2. 通过两次遍历分别获得两个链表的长度，然后计算长度差t，从长度较大的链表头开始先遍历t个结点
 * 接下来两个链表就变成相同长度了，依次遍历每个结点进行比较即可
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};

int get_list_length(ListNode* list) {
    int len = 0;
    while (list) {
        ++len;
        list = list->next;
    }
    return len;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1 || !pHead2) {
        return NULL;
    }
    auto len1 = get_list_length(pHead1);
    auto len2 = get_list_length(pHead2);
    int dif = 0;
    auto long_list = pHead1;
    auto short_list = pHead2;
    dif = len1 - len2;
    if (len1 < len2) {
        long_list = pHead2;
        short_list = pHead1;
        dif = len2 - len1;
    }
    for (int i = 0; i < dif; i++) {
        long_list = long_list->next;
    }

    while ((long_list != NULL) && (short_list != NULL) && long_list != short_list) {
        long_list = long_list->next;
        short_list = short_list->next;
    }
    return short_list;
}

int main() {
    auto node1 = new ListNode(1);
    auto node2 = new ListNode(2);
    auto node3 = new ListNode(3);
    auto node4 = new ListNode(4);
    auto node5 = new ListNode(5);
    auto node6 = new ListNode(6);
    auto node7 = new ListNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node6;

    node4->next = node5;
    node5->next = node6;

    node6->next = node7;

    auto ret = FindFirstCommonNode(node1, node4);
    cout << ret->val << endl; // 6
    return 0;
}
