#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

int maxD;
    int getPath(TreeNode* root) {
        if(root == nullptr)
        return 0;
        else {
            int left = getPath(root->left);
            int right = getPath(root->right);
            maxD = max(left+right, maxD);
            return 1 + max(left,right);
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxD = -99999;
        getPath(root);
        return maxD;
    }


int main(){
}