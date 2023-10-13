#include<bits/stdc++.h>
#include "../Headers/tree.h"
using namespace std;
//ACCEPTED SOLUTION
TreeNode* makeMirrorImage(TreeNode* root)
    {
        if(root == nullptr) return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        makeMirrorImage(root->left);
        makeMirrorImage(root->right);
        return root;
    }

    bool checkIdentical(TreeNode* root1, TreeNode* root2)
    {
        if(root1==nullptr && root2==nullptr) return true;
        if(root1 != nullptr && root2 != nullptr && root1->val == root2->val) 
        return checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
        else return false;

    }

    bool isSymmetric(TreeNode* root) {
        return checkIdentical(makeMirrorImage(root->left), root->right);
    }

int main(){
}