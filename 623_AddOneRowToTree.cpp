#include <bits/stdc++.h>
using namespace std;
//Solution: https://leetcode.com/problems/add-one-row-to-tree/submissions/815827889/
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Queue{
public:
    TreeNode *node;
    int depth;
    Queue()
    {
        this->node = nullptr;
        this->depth = 0;
    }
    Queue(TreeNode *node, int val)
    {
        this->node = node;
        this->depth = val;
    }
};
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode *temp2 = new TreeNode();
        if(depth==1)
        {
            temp2 = new TreeNode(val,root,nullptr);
            return temp2;
        }
        else
        {
            int d=0;
            vector<Queue*>queue;
            Queue *temp;
            queue.push_back(new Queue(root,1));
            while(!queue.empty())
            {
                temp = queue[0];
                vector<Queue*>::iterator i=queue.begin();
                queue.erase(i);
                if(temp->depth==depth-1)
                {
                    TreeNode *left = new TreeNode(val,temp->node->left, nullptr);
                    TreeNode *right = new TreeNode(val,nullptr,temp->node->right);
                    temp->node->left = left;
                    temp->node->right = right;
                }
                else
                {
                    if(temp->node->left!=nullptr)
                    queue.push_back(new Queue(temp->node->left,temp->depth+1));
                    if(temp->node->right!=nullptr)
                    queue.push_back(new Queue(temp->node->right,temp->depth+1));
                }
            }
        }
        return root;
    }
};