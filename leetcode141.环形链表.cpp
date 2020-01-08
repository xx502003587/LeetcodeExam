/*
 * 题意：
 * 给定一个单链表
 * 1. 判断链表中是否有环
 * 2. 如果有环，输出环的第一个节点；否则输出Null
 * 3. 如果有环，输出环的长度；否则输出-1
 * 4. 如果有环，将环去除（修改为无环单链表）
 *
 * 思路：
 * 使用双指针法判断链表中是否有环，将两个指针slow和fast都指向头结点，然后slow每次走一步，fast每次走两步
 * 如果链表中存在环，那么slow和fast一定会在环上的某一个节点相遇。
 * 为什么两者一定会相遇？
 * slow每次走一步，fast每次走两步，因为fast先进入环，当slow进入环之后
 * 如果将slow看做在前面，fast在后面，那么每一次fast都会向slow靠近1，所以一定会相遇，而不会出现直接跳过slow的情况
 * 
 * 将链表的头结点标记为 X，环的第一个节点标记为Y，记录X-Y的长度为len(X,Y)=a
 * 假设 slow 和 fast 在环中的Z点相遇，记录Y-Z的长度为len(Y,Z)=b
 * 当从Z点继续前进最终还会经过Y，记录Z-Y的长度为len(Z,Y)=c
 * 通过数学表达式来寻找规律：
 * 当 slow 和 fast 相遇时，他们所用的时间一样，因为 fast 的速度是 slow 的2倍，所以 fast 走的节点数也是 slow 的2倍
 * 即：fast走过了a+b+c+b，slow走过了a+b，所以有等式 2*(a+b) = a+b+c+b，即 a=c
 * a=c 表明：从头结点 X 走到环的第一个节点 Y 的长度 和 从相遇的地方再一次走到 环的第一个节点Y 的长度 相同
 * 利用这个性质来进行解答，具体每一问的思路写在对应的方法注释中
 * 
 * 一个比较容易理解的解释：https://blog.csdn.net/xy010902100449/article/details/48995255#commentsedit
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

/*
 * 1. 判断是否有环
 * 使用快慢指针，快指针每次走两步，慢指针每次走一步，如果两个没有环，那么快指针会走到单链表的末尾（即当前节点为空，或下一个节点为空）
 * 如果在快指针走到末尾之前，两个指针相遇，则表明有环存在
 */
bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    auto slow = head;
    auto fast = head->next;
    while (slow != fast) {
        // 由于fast每次走两步，所以判断是否无环的情况是当前为空或者下一个为空
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

/*
 * 2. 如果有环，输出环的第一个节点；否则输出Null
 * 首先使用1中的方法判断链表是否有环，如果没有环输出NULL
 * 如果有环，先记录下快慢指针相遇的节点，根据上面公式的推导我们得出了 a=c 这个性质
 * 即：从头结点 X 走到环的第一个节点 Y 的长度 和 从相遇的地方再一次走到 环的第一个节点Y 的长度 相同
 * 根据这个性质，当快慢指针相遇时，令慢指针指向头结点，令快指针指向相遇节点的下一个节点，然后快慢指针每次各走一步，当二者相遇时，相遇节点就是环的第一个节点
 */
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    auto slow = head;
    auto fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    // 表明提前结束了循环，即没有环存在
    if (slow != fast) {
        return nullptr;
    }
    slow = head;
    // 相遇时，相遇节点Z到Y还有 Y-X+2 个结点（包括相遇节点本身），而头结点到环的入口节点Y还有 Y-X+1 个结点（包括头结点本身）
    // 所以 fast 需要向前走一步才能保证同时到达 Y
    fast = fast->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

/*
 * 3. 如果有环，输出环的长度；否则输出-1
 * 如果有环，根据上面公式的推导我们得出了 a=c 这个性质
 * 即：从头结点 X 走到环的第一个节点 Y 的长度 和 从相遇的地方再一次走到 环的第一个节点Y 的长度 相同
 * 由于 b+c 的长度就是环的长度，而 a=c，那么根据这个性质可以发现a+b就是环的长度，而a+b的长度正好是快慢指针在环中相遇时慢指针走过的长度
 * 所以，在使用1中方法进行是否有环的判断时，维护一个步数计数器，每次slow走一步后对计数器+1
 * 如果不存在环，直接返回-1；如果存在环，那么快慢指针相遇时 慢指针刚好走过了 a+b 的长度，直接返回计数器的值即可
 */
int countCycleLength(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return -1;
    }
    auto slow = head;
    auto fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast) {
        return -1;
    }
    int len = 1;
    fast = fast->next;
    while (slow != fast) {
        fast = fast->next;
        ++len;
    }
    return len;
}

/*
 * 4. 如果有环，将环去除（修改为无环单链表）
 * 根据2中寻找环的第一个节点的方法，在快慢指针相遇时，将slow指向头结点，然后维护一个指针pre指向相遇节点，将fast指向相遇节点的下一个节点，然后3个指针同时按照1的步幅前进
 * 当slow和fast相遇时，指向的节点是环的第一个节点，而此时pre指向的是前一个节点，即使单链表构成环的节点，将pre指向的节点的next指向空，就断开了环
 */
void removeCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    auto slow = head;
    auto fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast) {
        return;
    }
    slow = head;
    auto t = fast;
    fast = fast->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        t = t->next;
    }
    t->next = nullptr;
    return;
}

int main() {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    // 输入一个单链表，判断是否有环
    auto has_cycle = hasCycle(node1);
    cout << "链表是否有环: " << (has_cycle ? "yes" : "no") << endl;

    // 输入一个单链表，链表如果有环，输出环的第一个节点；否则输出null
    auto ret = detectCycle(node1);
    cout << "链表环的第一个节点:" << ret->val << endl;

    // 输入一个单链表，链表如果有环，输出环的长度；否则输出-1
    auto len = countCycleLength(node1);
    cout << "链表环的长度: " << len << endl;

    //
    removeCycle(node1);
    cout << "去掉链表环: ";
    while (node1 != nullptr) {
        cout << node1->val << " ";
        node1 = node1->next;
    }

    return 0;
}