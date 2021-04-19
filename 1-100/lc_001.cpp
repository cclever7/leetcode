/**
 * 两数之和
 * 
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现
 * 
 * 示例:
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = mp.find(target - nums[i]);
            if(iter != mp.end()) {
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            } 
            mp.insert(make_pair(nums[i], i));
        }
        return res;
    }
};

int main() {
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    Solution s; 
    vector<int> res = s.twoSum(v, 9);
    for(int i : res) {
        cout << i << endl;
    }

}