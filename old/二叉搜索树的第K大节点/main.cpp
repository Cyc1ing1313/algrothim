struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    int res = 0;
    int cout = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }

    void dfs(TreeNode* root,int k){
        if(root==nullptr){
            return;
        }
        dfs(root->right,k);
        cout++;
        if(cout == k){
            res = root->val;
        }
        dfs(root->left,k);
    }
};