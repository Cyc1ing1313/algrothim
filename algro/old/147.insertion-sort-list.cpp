/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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

//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  }
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* l = head->next;
        head->next = nullptr;
        while(l!=nullptr){
            ListNode* t = l->next;
            head = insert(head,l);
            l = t;
        }
        return head;

    }

    ListNode* insert(ListNode* head,ListNode* node){
        if(node->val < head->val){
            node->next = head;
            return node;
        }
        ListNode* ret = head;
        while(head!=nullptr){
            if(head->next == nullptr){
                head->next = node;
                node->next = nullptr;
                break;
            }
            if(head->next->val > node->val){
                ListNode* t = head->next;
                head->next = node;
                node->next = t;
                break;
            }
            head = head->next;
        }
        return ret;
    }
};
// @lc code=end

