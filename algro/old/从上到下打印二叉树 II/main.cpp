#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(0,root);
        return ret;
    }

    void dfs(int level,TreeNode* root){
        if(!root){
            return;
        }
        if(level >= ret.size()){
            ret.push_back(vector<int>());
        }
        ret[level].push_back(root->val);
        dfs(level+1,root->left);
        dfs(level+1,root->right);
    }
};