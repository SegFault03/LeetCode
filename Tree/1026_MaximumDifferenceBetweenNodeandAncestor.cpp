#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int v = -99999;
    //Store max,min of every subtree, compare that with the root node val, check against v, return new max, min
    pair<int,int> findV(TreeNode *root){
        int maxC, minC, minA, maxA, tempV;
        pair<int,int>L{99999, -99999}, R{99999, -99999};
        if(root->left!=nullptr)
        L = findV(root->left);
        if(root->right!=nullptr)
        R = findV(root->right);
        if(root->left==nullptr && root->right==nullptr)
        return {root->val, root->val};
        maxC = max(L.second, R.second);
        minC = min(L.first, R.first);
        maxA = abs(root->val - maxC);
        minA = abs(root->val - minC);
        tempV = max(maxA, minA);
        v = tempV>v?tempV:v;
        return {min(minC, root->val),max(maxC, root->val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        findV(root);
        return v;
    }


int main(){
    string s = "[8,3,10,1,6,null,14,null,null,4,7,13]";
    vector<string>t = VectorParser::convertToStringVector(s);
    TreeNode *root = TreeNode::makeTreeUsingStringElements(t);
    cout<<maxAncestorDiff(root);
}