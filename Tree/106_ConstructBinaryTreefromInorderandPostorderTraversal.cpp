#include<bits/stdc++.h>
#include "../Headers/tree.h"
using namespace std;
//ACCEPTED SOLUTION
TreeNode* makeTree(
        vector<int>& inorder, 
        vector<int>& postorder,
        int l,
        int r,
        int *p)
    {
        if(l>r) return nullptr;
        int root = postorder[*p], i;
        *p-=1;
        for(i=l; i<=r; i++)
        {
            if(root==inorder[i]) break;
        }
        TreeNode *rootNode = new TreeNode(root);
        rootNode->right = makeTree(inorder,postorder,i+1,r,p);
        rootNode->left = makeTree(inorder,postorder,l,i-1,p);
        return rootNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p = postorder.size()-1;
        return makeTree(inorder, postorder,0,p,&p);
    }

int main(){
}