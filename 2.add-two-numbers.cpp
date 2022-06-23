/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int t=0,a;
    ListNode *head = new ListNode();
    ListNode *p=  head;
    ListNode *tt;
    while(l1&&l2){
      a = l1->val+l2->val+t;
      t = a/10;
      tt = new ListNode(a%10);
      p->next = tt;
      p = p->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    if(l2) {
      l1 = l2;
    }
    if(l1){
      p->next = l1;
      p = p->next;
      while(p){
          a = p->val+t;
          t = a/10;
          p->val = a%10;
          if(!p->next && t) {
            break;
          }
          p = p->next;
      }
    }
    if(t){
      p->next = new ListNode(t);
    }
    return head->next;
  }
};
// @lc code=end
