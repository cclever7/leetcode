/**
 * 最后一个单词的长度
 * 
 * 给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
 * 
 * 示例 1：
 * 输入：s = "Hello World"
 * 输出：5
 * 
 * 示例 2：
 * 输入：s = "Hello "
 * 输出：5
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int sz = s.size();
        int res = 0;
        for(int i = sz - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                res++;
            } else if(res != 0) {
                break;
            }
        }
        return res;
    }
};

int main() {
    string str = "a ";
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}