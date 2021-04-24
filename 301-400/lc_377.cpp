/**
 * 组合总和 Ⅳ
 * 
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 题目数据保证答案符合 32 位整数范围。
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 解法：深度优先搜索遍历 + 动态规划剪枝
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int res = 0;
    int value = 0;
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i)
            for(const int& x : nums)
                if(i >= x)
                    dp[i] += dp[i-x];
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    cout << s.combinationSum4(nums, target) << endl;
    return 0;
}