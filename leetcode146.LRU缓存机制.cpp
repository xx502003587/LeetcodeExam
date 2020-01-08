/*
 * 题意：
 *
 *
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    // 存储 key--链表迭代器 的映射关系
    unordered_map<int, list<pair<int, int>>::iterator> map;
    // 双向链表
    list<pair<int, int>> cache;
    // 缓存容量
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // 访问的 key 不存在
        if (map.count(key) == 0) {
            return -1;
        }
        // key 存在，把 (k, v) 换到队头
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // 更新 (k, v) 在 cache 中的位置
        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int val) {
        //
        if (map.count(key) == 0) {
            // 双向链表容量已满，需要将链表尾部的节点删除，并将新节点插入到链表头部
            if (cache.size() == capacity) {
                // 删除 map 中的数据
                auto last_key = cache.back().first;
                map.erase(last_key);
                // 删除 cache 中的数据
                cache.pop_back();
            }
            // 双向链表容量未满，直接将新节点插入到链表头部
            // 修改 cache 中的数据
            cache.push_front(make_pair(key, val));
            // 修改 map 中的数据
            map[key] = cache.begin();
        }
        // key 存在，将节点换到队列头，修改 map 中对应的值
        else {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, val));
            map[key] = cache.begin();
        }
    }
};


int main() {
    LRUCache* cache = new LRUCache( 2 /* 缓存容量 */ );

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // 返回  1
    cache->put(3, 3);   // 该操作会使得密钥 2 作废
    cout << cache->get(2) << endl;       // 返回 -1 (未找到)
    cache->put(4, 4);   // 该操作会使得密钥 1 作废
    cout << cache->get(1) << endl;       // 返回 -1 (未找到)
    cout << cache->get(3) << endl;       // 返回  3
    cout << cache->get(4) << endl;       // 返回  4
    return 0;
}
