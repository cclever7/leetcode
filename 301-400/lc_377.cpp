/**
 * 
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