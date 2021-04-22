/**
 * 2的幂
 * 
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 2:
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 解法：
 * 1. 不断除以2 
 * 2. n & (n - 1) == 0
 *    如果一个数是2的次方，那个其二进制肯定为
 *    2 10
 *    4 100
 *    8 1000
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfTwo(16) << endl;
    return 0;
}