/*
 * 题目：
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
 * 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 
 * 思路：
 * 1. 遍历一次可以找到最小的数，时间复杂度为O(n)，不是本题考查的重点
 * 2. 利用局部有序的特性，使用二分法来进行查找，时间复杂度为O(logn)
 * 因为数组分为两个部分，两个部分都按照递增排序，并且前半部分的数都比后半部分的数大
 * 所以使用双指针分别指向第一个元素和最后一个元素，接着可以找到中间指针mid指向的元素。
 * 如果这个元素处于前半部分的递增数组中，那么它应该 >= 左指针指向的数，表明要查找的数在该元素右边，所以将左指针指向该位置
 * 如果这个元素处于后半部分的递增数组中，那么它应该 <= 右指针指向的数，表明要查找的数在该元素左边，所以将右指针指向该位置
 * 因此，左指针总是指向前半部分的递增数组，右指针总是指向后半部分的递增数组，
 * 最终左指针将指向前半部分递增数组的最后一个，右指针将指向后半部分递增数组的第一个
 * 所以两个指针相邻，则右指针指向的数就是最小的数
 * 如：[3,4,5,1,2]
 * 
 * 特例：
 * 上述步骤中，对于[3,4,5,1,2]，mid指针指向5时，比左指针大，同时也大于右指针
 * 对于[4,5,1,2,3]，mid指针指向1时，比左指针小，同时也小于右指针
 * 若对于[2,1,2,2,2]，可以看做是[1,2,2,2,2]的一个旋转数组，
 * 当mid指向下标为2的2时，三个指针所指向的数都相等，此时无法判断mid指向的数在前面子数组还是后面子数组中
 * 对于此种情况，只能在两个指针之间进行顺序查找来判断最小值
 */

#include <iostream>
#include <vector>

using namespace std;

// 顺序查找 left ~ right 之间的最小值
int minInorder(vector<int>& rotateArray, int left, int right) {
    int ret = rotateArray[left];
    for (int i = left + 1; i <= right; ++i) {
        ret = (rotateArray[i] < ret) ? rotateArray[i] : ret;
    }
    return ret;
}

int minNumberInRotateArray(vector<int>& rotateArray) {
    if (rotateArray.empty()) {
        return 0;
    }
    int size = rotateArray.size();
    int left = 0;
    int right = size - 1;
    int mid = left;
    // 当左指针的数 >= 右指针的数时进入循环
    // 即：如果数组本身就是从前到后的有序状态，则左指针比右指针小，直接返回mid指向的值（初始化为左指针）即可
    while (rotateArray[left] >= rotateArray[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
        mid = left + (right - left) / 2;
        // 当三个指针的数相等时，无法判断mid在前半部分还是后半部分，只能顺序查找
        if (rotateArray[mid] == rotateArray[left]
            && rotateArray[mid] == rotateArray[right]) {
            return minInorder(rotateArray, left, right);
        }
        // 二分调整区间
        if (rotateArray[mid] >= rotateArray[left]) {
            left = mid;
        } else if (rotateArray[mid] <= rotateArray[right]) {
            right = mid;
        }
    }
    return rotateArray[mid];
}

int main() {
    //vector<int> input = {3,4,5,1,2};
    vector<int> input = {2,1,2,2,2};
    auto ret = minNumberInRotateArray(input);
    cout << ret << endl;
    return 0;
}
