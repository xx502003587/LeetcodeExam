/*
 * 题意：
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1]
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 * 不能使用除法。
 *
 * 思路：
 * 使用两个辅助数组left和right
 * left存储从数组左端点开始到当前位置时，左边所有值的乘积，显然left[0]=1
 * right存储从数组右端点开始到当前位置时，右边所有值的乘积，显然right[right.length()-1]=1
 * 最后计算B的时候，对于索引值i，其左边的乘积乘以右边的乘积就是所求的值，即left[i]*right[i]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A) {
    vector<int> B(A.size(), 1);
    if (A.empty()) {
        return B;
    }
    // 从左边开始计算乘积
    vector<int> left(A.size(), 1);
    for (int i = 1; i < A.size(); ++i) {
        left[i] = left[i-1] * A[i-1];
    }
    // 从右边开始计算乘积
    vector<int> right(A.size(), 1);
    for (int i = A.size() - 2; i >= 0; --i) {
        right[i] = right[i+1] * A[i+1];
    }
    // 计算B
    for (int i = 0; i < B.size(); i++) {
        B[i] = left[i] * right[i];
    }
    return B;
}

int main() {
    vector<int> input = {3, 4, 5, 1, 2};
    auto ret = multiply(input); // 40=4*5*2, 30=3*5*2, 24=3*4*2, 120=3*4*5*2, 60=3*4*5
    for (auto item : ret) {
        cout << item << " "; 
    }
    return 0;
}
