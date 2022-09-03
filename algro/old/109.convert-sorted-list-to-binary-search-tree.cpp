/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);
    }

    ListNode* getMid(ListNode* head,ListNode* end){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=end && fast->next!=end){
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* head,ListNode* end){
        if(head == end) return nullptr;
        ListNode* mid = getMid(head,end);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(head,mid);
        root->right = buildTree(mid->next,end);
        return root;

    }
};
// @lc code=end

