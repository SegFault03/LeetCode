#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;
/**
 * ACCEPTED SOLN.
 */
TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeStore;
        unordered_set<int>rootStore;
        TreeNode *tempRoot = nullptr, *child = nullptr;
        for (auto description : descriptions) {
            tempRoot = nodeStore.find(description[0]) == nodeStore.end()
                           ? new TreeNode(description[0])
                           : nodeStore[description[0]];
            child = nodeStore.find(description[1]) == nodeStore.end()
                        ? new TreeNode(description[1])
                        : nodeStore[description[1]];
            nodeStore[description[0]] = tempRoot;
            nodeStore[description[1]] = child;
            if (description[2] == 1) {
                tempRoot->left = child;
            } else {
                tempRoot->right = child;
            }
            rootStore.insert(description[0]);
        }
        for(auto description: descriptions){
            if(rootStore.find(description[1])!=rootStore.end())
            rootStore.erase(description[1]);      
        }
        return nodeStore[*rootStore.begin()];
    }


int main(){
}