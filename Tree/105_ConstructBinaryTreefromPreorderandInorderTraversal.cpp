#include<bits/stdc++.h>
#include "../Headers/tree.h"
using namespace std;
//ACCEPTED SOLUTION
TreeNode* makeTree(
        vector<int>& inorder, 
        vector<int>& preorder,
        int l,
        int r,
        int *p
        )
{
        if(l>r) return nullptr;
        int root = preorder[*p],i;
        for(i = l; i<=r; i++)
        {
            if(inorder[i]==root) break;
        }
        *p+=1;
        TreeNode *rootNode = new TreeNode(root);
        rootNode->left = makeTree(inorder,preorder,l,i-1,p);
        rootNode->right = makeTree(inorder,preorder,i+1,r,p);
        return rootNode;
}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    int p = 0;
    return makeTree(inorder,preorder,0,preorder.size()-1,&p);
}
int main(){
    vector<int>in = {9,3,15,20,7};
    vector<int>pre = {3,9,20,15,7};
    buildTree(pre,in)->DFS();
}