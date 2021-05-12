/**
 * 子数组异或查询
 * 
 * 有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
 * 对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。
 * 并返回一个包含给定查询 queries 所有结果的数组。
 * 
 * 示例：
 * 输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
 * 输出：[2,7,14,8] 
 * 解释：
 * 数组中元素的二进制表示形式是：
 * 1 = 0001 
 * 3 = 0011 
 * 4 = 0100 
 * 8 = 1000 
 * 查询的 XOR 值为：
 * [0,1] = 1 xor 3 = 2 
 * [1,2] = 3 xor 4 = 7 
 * [0,3] = 1 xor 3 xor 4 xor 8 = 14 
 * [3,3] = 8
 * 
 * 解法：
 * 利用异或的性质: a^b=c; 则a^c=b；
 * 举例来说就是： a[0] ^ a[1] ^ a[2] = ?
 * 要求得 a[1] ^ a[2], 只需要 ? ^ a[0] = a[1] ^ a[2]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        if(arr.size() <= 0 || queries.size() <= 0)
            return res;
        vector<int> dp(arr.size());
        dp[0] = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            dp[i] = dp[i - 1] ^ arr[i];
        }
        for(int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            int value = 0;
            if(start == 0) {
                value = dp[end];
            } else {
                value = dp[end] ^ dp[start - 1];
            }
            res.push_back(value);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1, 3, 4 , 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> res = s.xorQueries(v1, queries);
    for(const int i : res) {
        cout << i << endl;
    }
    return 0;
}