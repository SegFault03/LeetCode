#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLN.
 * Intuition and Logic:
 * 
 * 1. In a BST, all nodes in the right subtree are greater than the current node.
 * 2. We need to sum up all greater values for each node.
 * 3. To achieve this, we use a reverse in-order traversal (right, root, left).
 * 4. We maintain a running sum of all greater values encountered so far.
 * 5. For each node, we:
 *    a) Process its right subtree
 *    b) Update its value with the running sum
 *    c) Add its original value to the running sum
 *    d) Process its left subtree
 * 6. We use recursion to traverse the tree, passing the sum from parent nodes down.
 * 7. The function returns the total sum of the subtree for use in parent calls.
 */

class Solution {
public:
    // Helper function to convert BST to Greater Tree
    int convertToGst(TreeNode* root, int parentSum) {
        if (root == nullptr) {
            return 0;  // Base case: empty subtree contributes no value
        }
        
        // Process right subtree first (greater values)
        int rightSum = convertToGst(root->right, parentSum);
        
        // Calculate total sum of greater values for current node
        int totalGreaterSum = rightSum + parentSum;
        
        // Store original value for later use
        int originalValue = root->val;
        
        // Update current node's value
        root->val += totalGreaterSum;
        
        // Process left subtree, passing down the updated sum
        int leftSum = convertToGst(root->left, root->val);
        
        // Return total sum of this subtree (for parent's use)
        return leftSum + originalValue + rightSum;
    }

    // Main function to convert BST to Greater Tree
    TreeNode* bstToGst(TreeNode* root) {
        convertToGst(root, 0);  // Start with initial parent sum of 0
        return root;  // Return the modified tree
    }
};

int main(){
}