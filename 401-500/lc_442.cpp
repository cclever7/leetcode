/**
 * 
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 * 找到所有出现两次的元素。
 * 
 * 解法：
 * 注意利用 1 ≤ a[i] ≤ n 条件
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0)
            return res;
        for(int i = 0; i < nums.size(); i++) {
            int value = std::abs(nums[i]) - 1;
            if(nums[value] < 0) {
                res.push_back(std::abs(nums[i]));
            } else {
                nums[value] *= -1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = s.findDuplicates(v);
    for(const int i : res) {
        cout << i << endl;
    }
    return 0;
}