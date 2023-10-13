#include<bits/stdc++.h>
#include "../Headers/node.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>>ans;
        vector<int>temp;
        deque<pair<TreeNode*,int>>dq;
        int currLvl = 0, lastLvl = 0;
        TreeNode *currNode = nullptr;
        dq.push_back({root,0});
        while(!dq.empty())
        {
            currNode = currLvl%2==0? dq.front().first: dq.back().first;
            currLvl = currLvl%2==0? dq.front().second: dq.back().second;
            if(currLvl!=lastLvl)
            {
                ans.push_back(temp);
                temp.clear();
                lastLvl = currLvl;
                continue;
            }

            if(currLvl%2==0)
            {
                dq.pop_front();
                if(currNode->left!=nullptr) dq.push_back({currNode->left, currLvl+1});
                if(currNode->right!=nullptr) dq.push_back({currNode->right, currLvl+1});           
            }

            else
            {
                dq.pop_back();
                if(currNode->right!=nullptr) dq.push_front({currNode->right, currLvl+1});
                if(currNode->left!=nullptr) dq.push_front({currNode->left, currLvl+1}); 
            }
            temp.push_back(currNode->val);
        }
        ans.push_back(temp);
        return ans;
    }


int main(){
    TreeNode *root = TreeNode::makeTree(VectorParser::convertToStringVector("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]"));
    VectorParser::printtwoDArray(zigzagLevelOrder(root));
}