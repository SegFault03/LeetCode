#include <bits/stdc++.h>
#include "../headers/tree.h"
using namespace std;

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->DFS();
}