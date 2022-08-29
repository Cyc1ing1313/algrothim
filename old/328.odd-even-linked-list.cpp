/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* ret = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int count = 2;
        while (curr!=nullptr)
        {
            if(count%2==1){
                prev->next = curr->next;
                curr->next = head->next;
                head->next = curr;
                head = head->next;
                
                curr = prev->next;
                count++;
            }else{
                count++;
                curr=curr->next;
                prev = prev->next;
            }  
        }
        return ret;
        
    }
};
// @lc code=end

