/**
 * Definition for a binary tree node.
 * Solution: https://leetcode.com/problems/path-sum/submissions/815849569/
 **/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        return false;
        else if(root->left==nullptr&&root->right==nullptr)
        return(targetSum-root->val==0?true:false);
        else
        return(hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val));
    }
};