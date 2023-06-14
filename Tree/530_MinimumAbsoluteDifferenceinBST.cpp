#include<bits/stdc++.h>
#include "../headers/tree.h"
using namespace std;

 void inOrder(TreeNode* root, vector<int>& elements)
    {
        if(root->left!=nullptr) inOrder(root->left, elements);
        elements.push_back(root->val);
        if(root->right!=nullptr) inOrder(root->right, elements);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>elements;
        inOrder(root, elements);
        int min = abs(elements[1] - elements[0]);
        for(int i = 2; i<elements.size(); i++)
        min = abs(elements[i] - elements[i-1]) < min? abs(elements[i] - elements[i-1]): min;
        return min;
    }

int main(){
    vector<string>test{"4","2","6","1","3"};
    TreeNode *root = TreeNode::makeTree(test);
    cout<<getMinimumDifference(root);
}