#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
int c = 0;
    void countGood(TreeNode *root, int maxN) {
        if(root!=nullptr) {
            if(root->val>=maxN) {
                c++;
                maxN = root->val;
            }
            countGood(root->left, maxN);
            countGood(root->right, maxN);
        }
    }
    int goodNodes(TreeNode* root) {
        countGood(root, -99999);
        return c;
    }

int main(){
}