/**
 * 移除链表元素
 * 
 * 给你一个链表的头节点 head 和一个整数 val ，
 * 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 示例 1：
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 */
#include <iostream>
#include "../common.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *iter = head, *prev = new_head;
        while(iter) {
            ListNode *next = iter->next;
            if(iter->val == val) {
                prev->next = next;
            } else {
                prev = iter;
            }
            iter = next;
        }
        return new_head->next;
    }
};

int main() {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(7);
    ListNode l4(7);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    Solution s;
    ListNode *iter = s.removeElements(&l1, 7);
    while(iter) {
        cout << iter->val << endl;
        iter = iter->next;
    }
    return 0;
}