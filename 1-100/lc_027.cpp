/**
 * 移除元素
 * 
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * 
 * 示例 1：
 * 输入：nums = [3,2,2,3], val = 3
 * 输出：2, nums = [2,2]
 * 解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
 * 例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
 * 
 * 解法：从后往前
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return nums.size();
        int size = nums.size();
        int k = size;
        for(int i = size - 1; i >= 0; i--) {
            if(nums[i] == val) {
                int j = i;
                while(j <= k - 2) {
                    nums[j] = nums[j + 1];
                    j++;
                }
                k--;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 3, 5};
    Solution s;
    int size = s.removeElement(nums, 3);
    for(int i = 0; i < size; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}