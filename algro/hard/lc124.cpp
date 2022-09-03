#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// 路径
// 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
// 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/binary-tree-maximum-path-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int global_max = 0;

class Solution {
public:

   int maxPathSum(TreeNode *root) {
    global_max = INT_MIN;
    helper(root);
    return global_max;
  }
   int helper(TreeNode *root) {
    if(!root) return 0;
    int left = helper(root->left);
    int right = helper(root->right);
    int t = max(0,left)+max(0,right)+root->val;
    int ret = max(max(left,right),0)+root->val;
    global_max = max(global_max,max(t,ret));
    return ret;
  }
};
