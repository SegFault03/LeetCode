#include<bits/stdc++.h>
#include "E:/Code/DSA_headers/Tree/tree.h"
using namespace std;

void inorder(Tree *root,vector<int>&array)
{
    if(root==nullptr)
    return;
    else
    {
        inorder(root->left,array);
        array.push_back(root->val);
        inorder(root->right,array);
    }
}

bool findTarget(Tree* root, int k) {
        vector<int>array;
        inorder(root,array);
        int j=0,t=array.size()-1;
        while(j<t)
        {
            int sum = array[j]+array[t];
            if(sum==k)
            return true;
            else if(sum>k)
            t--;
            else
            j++;
        }
        return false;   
}

int main(){
    Tree *tree = getInput();
    cout<<findTarget(tree,9);
}