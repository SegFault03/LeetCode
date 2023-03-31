#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
        int val;
        TreeNode* left;
        TreeNode* right;

public:
        TreeNode()
        {
            this->val = 0;
            this->left = nullptr;
            this->right = nullptr;
        }

        TreeNode(int val)
        {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }

        TreeNode(int val, TreeNode* left, TreeNode* right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }

        void DFS()
        {
            if(this!=nullptr)
            {
                cout<<this->val<<" ";
               this->left->DFS();
               this->right->DFS();
            }
        }
};
