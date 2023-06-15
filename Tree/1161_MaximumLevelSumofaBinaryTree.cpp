/*
Core logic is quite simple:
i. Use BFS to perform level order traversal, and keep track of the sum of nodes at each level
ii. Since we're performing level order, all the nodes which are at the same level WILL be traversed first,
so keep a track of the level that is currently being traversed. Meaning all nodes at lvl 2 will be traversed
continuously, in a sequential manner, before moving to lvl 3, we won't randomly jump to a node of lvl 3. 
This means we can easily detect a lvl change. (For eg. when we see the current node is on lvl 3, and
the last node was on lvl 2, we can say that we have completed lvl 2)
iii. When the level changes, update max sum with the sum calculated for the last level. IF sum and max
is equal, consider the level which is smaller.
ACCEPTED SOLUTION
*/
#include<bits/stdc++.h>
#include "../headers/tree.h"
using namespace std;

int maxLevelSum(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return 1;
        int max = -99999, currLvl = 1, minLvl = 1, s = 0, lvl;      //currLvl keeps track of the current lvl
        queue<pair<TreeNode*,int>>queue;
        queue.push({root,1});                                       //initially, lvl is 1
        while(!queue.empty())
        {
            TreeNode *temp = queue.front().first;
            lvl = queue.front().second;
            queue.pop();
            if(lvl==currLvl) s += temp->val;                        //add node value to sum if traversing the same lvl
            else {                                                  //On level change, update max 
                if(s >= max)
                {
                    if(s==max)
                    {
                        if(currLvl < minLvl)                        //if sums are equal, consider the smaller lvl
                        minLvl = currLvl;
                    }
                    else
                    {
                        max = s;
                        minLvl = currLvl;
                    }
                }
                s = 0;                                              //refresh lvl sum and currLvl for the new lvl
                s += temp->val;
                currLvl = lvl;
            }
            if(temp->right!=nullptr) queue.push({temp->right, lvl+1});
            if(temp->left!=nullptr) queue.push({temp->left, lvl+1});
        }
        if(s >= max)
        {
            if(s==max)
            {
                if(currLvl < minLvl)
                minLvl = currLvl;
            }
            else
            {
                max = s;
                minLvl = currLvl;
            }
        }
        return minLvl;
    }

int main(){
}