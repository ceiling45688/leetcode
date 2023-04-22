/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // method: two pointers
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* newList = new ListNode();
        ListNode* tail = newList;

        while(p!=nullptr && q!=nullptr) {
            if(p->val <= q->val){
                tail->next = p;
                p = p->next;
            }else{
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }
        if(p!=nullptr){
            tail->next = p;
        }else{
            tail->next = q;
        }
        return newList->next;
    }
};
// @lc code=end

