#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode* p = head;
        for(int i=0;i<k;i++){
            if(!p) return head;
            p = p->next;
        }
        auto res = reverse(head,p);
        head->next = reverseKGroup(p,k);
        return res;
    }

    
    ListNode* reverse(ListNode* head,ListNode *end) {
        if(head==end || head->next == end) {
            return head;
        }
        ListNode* new_head = reverse(head->next,end);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
返回该题
