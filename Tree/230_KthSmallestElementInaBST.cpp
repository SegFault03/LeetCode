#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int ele, pos;
    int inorder(TreeNode* root, int n)
    {
        if(root==nullptr) return n;
        int l = inorder(root->left,n);
        if(l==-1) return -1;
        l++;
        if(l==pos)
        {
            ele = root->val;
            return(-1);
        }
        return(inorder(root->right, l));
    }
    int kthSmallest(TreeNode* root, int k) {
        pos = k;
        inorder(root,0);
        return ele;
    }

int main(){
}