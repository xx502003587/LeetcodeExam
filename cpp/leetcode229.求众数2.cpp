/*
 *
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ret;
    if (nums.size() == 0) {
        return ret;
    }
    int n1 = 0, n2 = 0;
    int cur1 = nums[0], cur2 = nums[0];
    
    for (auto num : nums) {
        if (cur1 == num) {
            n1++;
        } else if (cur2 == num) {
            n2++;
        } else if (n1 == 0) {
            cur1 = num;
            ++n1;
        } else if (n2 == 0) {
            cur2 = num;
            ++n2;
        } else {
            n1--;
            n2--;
        }
    }
    
    n1 = 0;
    n2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == cur1) {
            n1++;
        }
        if (nums[i] == cur2) {
            n2++;
        }
    }
    
    if (n1 > nums.size() / 3) {
        ret.push_back(cur1);
    }
    if (cur1 != cur2 && n2 > nums.size() / 3) {
        ret.push_back(cur2);
    }
    return ret;   
}

int main() {
    vector<int> input = {1,2};
    auto ret = majorityElement(input);
    for (auto item : ret) {
        cout << item << endl;
    }
    return 0;
}
