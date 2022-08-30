/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || k == 0) return head;
        
        ListNode* prev = head, curr = head->next,t;
        ListNode* next = 
        while(k-1>0){
            t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
            k--;
        }
        
        
    }

    int nextK(ListNode* head,k){
        ListNode* t = head;
        while(t){
            t=t->next;
            k--;
        }
        if(k<0) return head;
        return t;
    }
};
// @lc code=end

