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

        static TreeNode* makeTree(vector<string>elements)
        {
            if(elements.size()==0 || elements[0]=="null")
            return nullptr;
            unordered_map<int, TreeNode*>referenceMap;
            for(int i = 0; i<elements.size(); i++)
            {
                if(elements[i]=="null") continue;
                int n = stoi(elements[i]);
                if(i==0)
                referenceMap[i] = new TreeNode(n);

                if((2*i+1) < elements.size() && elements[2*i+1]!="null")
                {
                    TreeNode *temp = new TreeNode(stoi(elements[2*i+1]));
                    referenceMap[i]->left = temp;
                    referenceMap[2*i+1] = temp;
                }

                if((2*i+2) < elements.size() && elements[2*i+2]!="null")
                {
                    TreeNode *temp = new TreeNode(stoi(elements[2*i+2]));
                    referenceMap[i]->right = temp;
                    referenceMap[2*i+2] = temp;
                }
            }
            return referenceMap[0];
        }
};
