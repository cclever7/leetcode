/**
 * 删除排序链表中的重复元素
 * 
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
 * 返回同样按升序排列的结果链表。
 * 
 * 示例 1：
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 */
#include <iostream>
#include "../common.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *fast = head;
        while(fast && fast->next) {
            if(fast->val == fast->next->val) {
                fast->next = fast->next->next;
            } else {
                fast = fast->next;
            }
        }
        return head;
    }
};