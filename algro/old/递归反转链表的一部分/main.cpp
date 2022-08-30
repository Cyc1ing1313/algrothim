#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
//迭代
    ListNode* reverseListV1(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre!=NULL){
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
    
//递归
    ListNode* reverseListV2(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* new_head = reverseListV2(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};