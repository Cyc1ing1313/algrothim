/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        return mergeK(lists.size()-1,lists);
    }

    ListNode* mergeK(int k,vector<ListNode*>& lists) {
        if (!k) return lists[k];
        if (k==1) return mergeTwo(lists[k-1],lists[k]); 
        return mergeTwo(lists[k],mergeK(k-1,lists));    
    }

    ListNode* mergeTwo(ListNode* a,ListNode* b){
        ListNode* p = new ListNode(0);
        ListNode* head = p;
        while(a && b){
            if(a->val<b->val) {p->next = a;a=a->next;}
            else {p->next = b;b=b->next;}
            p=p->next;
        }
        if(a) p->next = a;
        if(b) p->next = b;
        return head->next;
    }

    
};
// @lc code=end

