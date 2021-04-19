/**
 * 有效的括号
 * 
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 示例 1：
 * 输入：s = "()"
 * 输出：true
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return false;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '(' || ch =='[' || ch == '{') {
                stk.push(ch);
            } else {
                if(stk.size() == 0)
                    return false;
                char top_ch = stk.top();
                stk.pop();
                if (ch == ')' && top_ch != '(') 
                    return false;
                else if(ch == ']' && top_ch != '[') 
                    return false;
                else if(ch == '}' && top_ch != '{') 
                    return false;
                else
                    ;
            }
        }
        if(stk.size() == 0)
            return true;
        else
            return false;
    }
};

int main() {
    string str = "((]}";
    Solution s;
    cout << s.isValid(str) << endl;
    return 0;
}