/**
 * 解码方法
 * 
 * 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
 * "AAJF" ，将消息分组为 (1 1 10 6)
 * "KJF" ，将消息分组为 (11 10 6)
 * 
 * 解法：动态规划
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')     
            return 0;
        int pre = 1, curr = 1;
        for(int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if(s[i] == '0') {
                if(s[i - 1] == '1' || s[i - 1] == '2')
                    curr = pre;
                else 
                    return 0;
            }
            else if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6') {
                curr = curr + pre;
            }
            pre = tmp;
        }
        return curr;
    }
};


int main() {
    Solution s;
    string str = "226";
    cout << s.numDecodings(str) << endl;
}