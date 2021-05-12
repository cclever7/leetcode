/**
 * 
 * 1486. 数组异或操作
 * 
 * 给你两个整数，n 和 start 。
 * 数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。
 * 请返回 nums 中所有元素按位异或（XOR）后得到的结果。
 * 
 * 示例 2：
 * 输入：n = 4, start = 3
 * 输出：8
 * 解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        if(n <= 0)
            return 0;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int value = start + 2 * i;
            v.push_back(value);
        }
        int sum = v[0];
        for(int i = 1; i < n; i++) {
            sum ^= v[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.xorOperation(5, 0) << endl;
    return 0;
}
