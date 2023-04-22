/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // method: two pointers
        ListNode* p = head;
        // q refers to the nth node behind the p
        ListNode* q = p;
        for(int i = 0; i < n; i++){
            q = q->next;
        }
        // 需要特殊处理头节点的情况
        if (q == NULL) {
            return head->next;
        }
        // 遍历到倒数第二个节点，此时p->next 为待移除node， q->next为最后一个节点
        while(q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        // 移除节点
        // p->next = p->next->next; 
        ListNode* tmp = p->next;
        p->next = tmp->next;
        delete tmp; // 防止内存泄漏
        return head;
        
    }
};
// @lc code=end

