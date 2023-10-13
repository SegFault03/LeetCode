#include<bits/stdc++.h>
#include "../Headers/node.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
vector<double> averageOfLevels(TreeNode* root) {
        if(root==nullptr)
        return vector<double>{0};
        vector<double>ans;
        queue<pair<TreeNode*,int>>queue;
        double lvlSum = 0;
        int n = 0, lastLvl=0;
        queue.push({root,0});
        while(!queue.empty())
        {
            TreeNode *currNode = queue.front().first;
            int currLvl = queue.front().second;
            queue.pop();
            if(currLvl != lastLvl)
            {
                ans.push_back(lvlSum/n);
                n = 0;
                lvlSum = 0;
                lastLvl = currLvl;
            }
            lvlSum+=currNode->val;
            n++;
            if(currNode->left!=nullptr) queue.push({currNode->left,currLvl+1});
            if(currNode->right!=nullptr) queue.push({currNode->right,currLvl+1}); 
        }
        ans.push_back(lvlSum/n);
        return ans;
    }

int main(){
}