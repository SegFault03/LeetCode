#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        return nullptr;
        if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right =deleteNode(root->right,key);
            return root;
        }
        else
        {
            if(root->left==nullptr && root->right==nullptr)
            return nullptr;
            else if(root->left!=nullptr && root->right==nullptr)
            return root->left;
            else if(root->left==nullptr && root->right!=nullptr)
            return root->right; 
            else
            {
                TreeNode *temp = root->left, *leftP = root->left;
                while(leftP->right!=nullptr)
                leftP = leftP->right;
                leftP->right = root->right;
                return temp;
            }
        }
    }


int main(){
}