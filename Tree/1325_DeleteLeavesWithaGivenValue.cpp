#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

/*ACCEPTED SOLUTION*/

TreeNode* removeLeafNodes(TreeNode* root, int target) {
            root->left = root->left == nullptr
                             ? nullptr
                             : removeLeafNodes(root->left, target);
            root->right = root->right == nullptr
                              ? nullptr
                              : removeLeafNodes(root->right, target);
            return root->val == target && root->left == nullptr &&
                           root->right == nullptr
                       ? nullptr
                       : root;

