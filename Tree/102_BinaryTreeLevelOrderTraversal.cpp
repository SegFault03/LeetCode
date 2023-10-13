#include<bits/stdc++.h>
#include "../Headers/node.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION

vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>>ans;
        vector<int>currLvlNodes;
        queue<pair<TreeNode*,int>>queue;
        int lastLvl=0, currLvl=0;
        queue.push({root,0});
        while(!queue.empty())
        {
            currLvl = queue.front().second;
            TreeNode *currNode = queue.front().first;
            queue.pop();
            if(currLvl != lastLvl)
            {
                ans.push_back(currLvlNodes);
                currLvlNodes.clear();
                lastLvl = currLvl;
            }
            if(currNode->left!=nullptr) queue.push({currNode->left,currLvl+1});
            if(currNode->right!=nullptr) queue.push({currNode->right,currLvl+1}); 
            currLvlNodes.push_back(currNode->val);
        }
        ans.push_back(currLvlNodes);
        return ans;
    }

int main(){
}