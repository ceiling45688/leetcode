/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // method: hashmap
        unordered_map<int, ListNode*> hashmap;
        ListNode* p = head;
        while (p != NULL) {
            if(hashmap.find(p->val) != hashmap.end()){
                return true;
            }else{
                //  val 是节点的值，value 是指向下一个节点的指针
                hashmap.insert({p->val, p->next});
            }
        }
        return false;
        
    }
};
// @lc code=end

