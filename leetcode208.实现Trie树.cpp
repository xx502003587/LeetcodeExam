/*
 * 题意：
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 *
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 26;

class Trie {
public:
    bool is_str;
    Trie *next[MAXN];

    Trie() {
        is_str = false;
        memset(next, 0, sizeof(next));
    }

    // 向 trie 树中插入一个单词
    void insert(string word) {
        // cur初始化为根结点指针
        Trie *cur = this;
        // 遍历word中的每一个字符
        for (char w : word) {
            // 如果下一个结点不存在，新增一个结点
            if (cur->next[w - 'a'] == NULL) {
                Trie *new_node = new Trie();
                cur->next[w - 'a'] = new_node;
            }
            cur = cur->next[w - 'a'];
        }
        // 当前结点已经是一个完整的字符串了
        cur->is_str = true;
    }

    // 判断 Trie 树中是否含有某个单词
    bool search(string word) {
        Trie *cur = this;
        for (char w : word) {
            // 更新cur指针的指向，使其指向下一个结点
            if (cur != NULL)
                cur = cur->next[w - 'a'];
        }
        // cur指针不为空且cur指针指向的结点为一个完整的字符串，则成功找到字符串
        return (cur != NULL && cur->is_str);
    }

    // 判断 Trie 树中是否有给定前缀的单词
    bool startsWith(string prefix) {
        Trie *cur = this;
        for (char w : prefix) {
            if (cur != NULL)
                cur = cur->next[w - 'a'];
        }
        // 相比search(),这里只需判断cur指针是否为空就行了
        return (cur != NULL);
    }
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple");   // 返回 true
    cout << trie->search("app");     // 返回 false
    cout << trie->startsWith("app"); // 返回 true
    trie->insert("app");
    cout << trie->search("app");     // 返回 true
    return 0;
}
