/*
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// 1. 快速排序法
// 利用快速排序（默认从小到大排序，第k大也就是第n-k小）
// 每一轮迭代将一个元素放到它最终的位置时，判断索引与n-k的大小关系，然后只递归一侧即可
int quickselect(vector<int>& nums, int left, int right, int k_smallest) {
    if (left == right) {
        return nums[left];
    }
    int base = nums[left];
    int tl = left, tr = right;
    while (tl < tr) {
        while (tl < tr && nums[tr] >= base)
            tr--;
        if (tl < tr) {
            nums[tl] = nums[tr];
            tl++;
        }
        while (tl < tr && nums[tl] <= base)
            tl++;
        if (tl < tr) {
            nums[tr] = nums[tl];
            tr--;
        }
    }
    nums[tl] = base;
    // 刚好是第k小，返回
    if (tl == k_smallest)
        return nums[tl];
    // 索引比k小，表明要求的值在当前索引的右边
    else if (tl < k_smallest)
        return quickselect(nums, tl+1, right, k_smallest);
    // 索引比k大，表明要求的值在当前索引的左边
    else
        return quickselect(nums, left, tl-1, k_smallest);
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n-1, n-k);
}

// 2. 堆排序法
// 大顶堆排序每一次会将最大的元素调出来，只需要循环K次即可找出第K大

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index) {
    int left = 2 * index + 1; // index的左子节点
    int right = 2 * index + 2;// index的右子节点

    int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx]) maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx]) maxIdx = right;

    // 当maxIdx不等于index时表明发生了元素互换，需要对换下去的节点进行调整，确保其符合大顶堆的特征
    if (maxIdx != index) {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}

int heapSort(vector<int> &arr, int size, int k_smallest) {
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--) {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for (int i = size - 1, k = 0; i >= 1, k < k_smallest; i--, k++) {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }

    return arr[size-k_smallest];
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return  heapSort(nums, nums.size(), k);
}

int main() {
    vector<int> input = {3,2,1,5,6,4};
    auto ret = findKthLargest(input, 2);
    cout << ret << endl;
    return 0;
}