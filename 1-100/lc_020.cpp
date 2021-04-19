
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