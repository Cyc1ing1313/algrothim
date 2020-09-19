#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr||B==nullptr){
            return false;
        }
        return hasSub(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);

    }



    bool hasSub(TreeNode* A,TreeNode* B){
        if(B == nullptr){
                return true;
        }
        if(A==nullptr || A->val != B->val){
                return false;
        }
        return  hasSub(A->left,B->left)&&hasSub(A->right,B->right);
    }
};