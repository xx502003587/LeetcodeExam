/*
 * 题目：
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 
 * 思路：
 * 根据数组的特性进行过滤并判断————同一行内从左往右递增，同一列内从上往下递增
 * 如果从(0,0)开始查找
 * 若target比当前位置的数小，表明target在当前位置的左边或者上边
 * 若target比当前位置的数大，表明target在当前位置的右边或者下边，这样会有一个重叠区域，比较麻烦
 * 如果从数组的右上角开始查找（从左下角同理）
 * 若target比当前位置的数小，表明target在当前位置的左边，只需将列号-1
 * 若target比当前位置的数大，表明target在当前位置的下边，只需将行号+1
 * 若target与当前位置的数相等，表明已经找到
 */

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
    bool ret = false;
    if (array.size() == 0) {
        return ret;
    }
    int rows = array.size();
    int cols = array[0].size();
    int r = 0;
    int c = cols - 1;
    while (r < rows && c >= 0) {
        if (array[r][c] == target) {
            ret = true;
            break;
        } else if (array[r][c] < target) {
            r++;
        } else {
            c--;
        }
    }
    return ret;
}

int main() {
    vector<vector<int>> input = {{1,2,8,9},
                                 {2,4,9,12},
                                 {4,7,10,13},
                                 {6,8,11,15}};
    vector<int> target = {3,7};
    for (int num : target) {
        if (Find(num,input)) {
            cout << num << " found" << endl;
        } else {
            cout << num << " not found" << endl;
        }
    }
    return 0;
}
