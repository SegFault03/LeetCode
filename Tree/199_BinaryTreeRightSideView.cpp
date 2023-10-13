#include<bits/stdc++.h>
#include "../Headers/tree.h"
//ACCEPTED SOLUTION
vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        vector<int>ans;
        queue<pair<TreeNode*,int>>queue;
        int lastLvl = 0;
        TreeNode *lastNode = nullptr;
        queue.push({root,0});
        while(!queue.empty())
        {
            int currLvl = queue.front().second;
            TreeNode *currNode = queue.front().first;
            queue.pop();
            if(currLvl != lastLvl)
            {
                ans.push_back(lastNode->val);
                lastLvl = currLvl;
            }
            if(currNode->left!=nullptr) queue.push({currNode->left,currLvl+1});
            if(currNode->right!=nullptr) queue.push({currNode->right,currLvl+1});
            lastNode = currNode;
        }
        ans.push_back(lastNode->val);
        return ans;
    }

using namespace std;
int main(){
}