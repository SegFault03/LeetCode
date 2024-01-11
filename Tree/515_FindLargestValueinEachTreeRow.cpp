#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * Standard BFS Tree traversal technique with a way of remmebering the current lvl
 * 
*/
vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return vector<int>{};
        int currLvl = 0, lmax = INT_MIN;
        vector<int>ans;
        queue<pair<TreeNode*,int>>queue;
        queue.push({root,0});                                               //the second member of the pair is used to save the current lvl
        while(!queue.empty()){
            TreeNode *node = queue.front().first;
            int lvl = queue.front().second;
            queue.pop();
            if(lvl!=currLvl){                                               //store the current lvl to detect lvl changes
                ans.push_back(lmax);
                lmax = node->val;
                currLvl = lvl;
            }
            if(node->left!=nullptr) queue.push({node->left, lvl+1});        //every child belongs to lvl = parent's lvl + 1
            if(node->right!=nullptr) queue.push({node->right, lvl+1});
            lmax = lmax<node->val?node->val:lmax;
        }
        ans.push_back(lmax);
        return ans;
    }


int main(){
}