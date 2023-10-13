#include<bits/stdc++.h>
#include "../Headers/tree.h"
using namespace std;
//ACCEPTED SOLUTION
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        TreeNode *lca = nullptr, *left = nullptr, *right = nullptr;
        if(root == p || root == q)
        lca = root;
        left = lowestCommonAncestor(root->left,p,q);
        right = lowestCommonAncestor(root->right,p,q);

        //either root itself is p or q, or its just null. 
        if(left==nullptr && right==nullptr)
        return lca;
        //left and right have found p and q, meaning root is the lca (both left and right can't be lca because all values are unique in the tree)
        else if(left!=nullptr && right!=nullptr) 
        return root;
        //One of left or right is not null -> one of p or q or maybe the lca itself has been found
        else 
        {
            //root is not an ancestor of itself, lca is either left or right, or left or right have p or q and lca is yet to be found
            if(lca == nullptr)              
            return left==nullptr?right:left;
            //root is one of p or q and is thus the nacestor, and the lca
            else 
            return root;
        }
    }

int main()
{

}