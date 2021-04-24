/**
 * 删除排序链表中的重复元素 II
 * 
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
 * 返回同样按升序排列的结果链表。
 * 
 * 示例：
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 */
#include <iostream>
#include "../common.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *prev = new_head, *curr = head, *next = nullptr;
        bool flag = false;
        while(next = curr->next) {
            if(curr->val == next->val) {
                curr = next;
                flag = true;
            } else {
                if(flag) {
                    flag = false;
                    prev->next = next;
                    curr = next;
                } else {
                    prev = curr;
                    curr = next;
                }
            }
        }
        if(flag == true) {
            prev->next = next;
            curr = next;
        }
        return new_head->next;
    }
};

int main() {
    ListNode l1(1);
    ListNode l2(1);
    // ListNode l3(3);
    // ListNode l4(3);
    // ListNode l5(4);
    // ListNode l6(4);
    // ListNode l7(5);
    l1.next = &l2;
    // l2.next = &l3;
    // l3.next = &l4;
    // l4.next = &l5;
    // l5.next = &l6;
    // l6.next = &l7;
    Solution s;
    ListNode *l = s.deleteDuplicates(&l1);
    while(l) {
        cout << l->val << endl;
        l = l->next;
    }
    return 0;
}