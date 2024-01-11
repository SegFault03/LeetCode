#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
pair<int,int>countNodes(TreeNode *root, int* count){
        if(root==nullptr) return {0,0};
        pair<int,int> a = {0,0},b={0,0};
        int totalSum = 0, totalNodes = 1;
        if(root->left!=nullptr)
        a = countNodes(root->left, count);
        if(root->right!=nullptr)
        b = countNodes(root->right, count);
        totalSum =  a.first + b.first + root->val;
        totalNodes += a.second + b.second;
        int avg = floor(totalSum/totalNodes);
        if(avg==root->val)
        *count = *count+1;
        return {totalSum,totalNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        countNodes(root, &count);
        return count;
    }


int main(){
    string test = "[4,8,5,0,1,null,6]";
    vector<string>testArr= VectorParser::convertToStringVector(test);
    TreeNode *root = TreeNode::makeTreeUsingStringElements(testArr);
    averageOfSubtree(root);
}