/**
 * 实现 strStr()
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 * 
 * 示例 1：
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 解法：
 * 1. 朴素解法 Yes
 * 2. KMP算法
 */
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if(len1 < len2) 
            return -1;
        if(len1 == 0 && len1 == len2) 
            return 0;

        for(int i = 0; i < len1; i++) {
            int k = i;
            bool flag = true;
            for(int j = 0; j < len2; j++) {
                if(haystack[k] == needle[j]) {
                    k++;
                } else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string a = "hello", b = "ll";
    Solution s;
    cout << s.strStr(a, b) << endl;
    return 0;
}