/*
 * 题意：
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 *
 * 思路：
 * 1. 快排
 * 快速排序每一轮迭代都会将一个数放到它最终的位置，如果这个数的下标是k，那么它左边的k个数就是最小的k个数（不一定有序）
 * 2. 堆排序
 * 使用大顶堆排序可以生成一个递增序列，使用小顶堆排序可以生成一个递减序列。
 * 堆排序每一轮会从所有数中挑出最大或最小的那个，放到数组的末尾，然后从剩余的树中进行迭代
 * 所以使用小顶堆排序只需要进行k轮，就可以挑出最小的k个数
 */

#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int> &arr, int len, int index) {
    int left = 2 * index + 1; // index的左子节点
    int right = 2 * index + 2;// index的右子节点

    int minIdx = index;
    if (left < len && arr[left] < arr[minIdx])
        minIdx = left;
    if (right < len && arr[right] < arr[minIdx])
        minIdx = right;

    if (minIdx != index) {
        swap(arr[minIdx], arr[index]);
        adjust(arr, len, minIdx);
    }
}

void heapSort(vector<int> &arr, int size, int k) {
    // 构建小顶堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--) {
        adjust(arr, size, i);
    }

    // 计算迭代次数
    int cnt = 0; 
    // 调整小根堆，当迭代进行k次之后就挑出来了k个数
    for (int i = size - 1; i >= 1, cnt < k; i--, ++cnt) {
        swap(arr[0], arr[i]);           // 将当前最小的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k > input.size()) {
        return vector<int>();
    }
    heapSort(input, input.size(), k);
    return vector<int>(input.end()-k, input.end());
}

int main() {
    vector<int> arr = {4,5,1,6,2,7,3,8};
    auto ret = GetLeastNumbers_Solution(arr, 4);
    for (auto item : ret) {
        cout << item << " ";
    }
    return 0;
}