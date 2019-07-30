/*
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size());
    int k = 1;
    // 使用数组存储每个位置除去当前元素后左边的元素乘积
    // [1，1，2，6] = [1，1*1，1*2，2*3]    
    for (int i = 0; i < nums.size(); ++i) {
        ret[i] = k;
        k *= nums[i]; 
    }
    k = 1; // k表示当前数右边的乘积
    // 更新数组 每个位置的数 = 左边的乘积 * 右边的乘积
    // [1*24=24，1*12=12，2*4=8，6*1=6]
    for (int i = nums.size() - 1; i >= 0; --i) {
        ret[i] *= k;
        k *= nums[i];
    }
    return ret;
}

int main() {
    vector<int> input = {1,2,3,4};
    auto ret = productExceptSelf(input);
    for (auto item : ret) {
        cout << item << " ";
    }

    return 0;
}
