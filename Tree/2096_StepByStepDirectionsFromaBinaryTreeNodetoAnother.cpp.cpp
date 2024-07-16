#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLUTION
Intuition and Logic:

1. Tree Traversal:
   - We perform a single depth-first search (DFS) traversal of the tree.
   - During traversal, we keep track of the current path from the root to the current node.
   - When we find either the start or destination node, we save the current path.

2. Path Representation:
   - We use vectors of characters to represent paths.
   - 'L' represents a left child, 'R' represents a right child.
   - This allows for efficient path construction and manipulation.

3. Finding the Common Ancestor:
   - After finding both paths, we compare them to find the common prefix.
   - The point where the paths diverge is the lowest common ancestor (LCA) of the start and destination nodes.

4. Constructing the Result:
   - From the start node, we move up to the LCA by adding 'U' for each step.
   - From the LCA, we follow the path to the destination node.

5. Optimization:
   - We use a single traversal to find both paths, reducing time complexity.
   - Vector operations (push_back and pop_back) are used for efficient path manipulation.
   - The search stops as soon as both paths are found, avoiding unnecessary traversals.

This approach efficiently solves the problem with O(n) time complexity, where n is the number of nodes in the tree.
The space complexity is O(h), where h is the height of the tree, due to the recursion stack and path storage.
*/
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> path;          // Current path during traversal
        vector<char> startPath;     // Path to start node
        vector<char> destPath;      // Path to destination node
        
        // Find paths to both start and destination nodes
        findPaths(root, startValue, destValue, startPath, destPath, path);
        
        // Find the length of the common prefix
        size_t i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }
        
        // Construct the result:
        // 1. Move up from start node to the common ancestor
        string result(startPath.size() - i, 'U');
        // 2. Move down from common ancestor to destination node
        result.append(destPath.begin() + i, destPath.end());
        
        return result;
    }

    /**
     * NOTE: Using vectors results in the solution being more memory efficient compared to using strings (even &string).
     * Note how a single vector (currentPath) is reused, thus saving memory.
     */
    bool findPaths(TreeNode* node, int startValue, int destValue, 
                   vector<char>& startPath, vector<char>& destPath, vector<char>& currentPath) {
        if (!node) return false;  // Base case: null node
        
        // Check if current node is start or destination
        if (node->val == startValue) {
            startPath = currentPath;
        }
        if (node->val == destValue) {
            destPath = currentPath;
        }
        
        // If both paths are found, we can stop the search
        if (!startPath.empty() && !destPath.empty()) {
            return true;
        }
        
        // Recursively search left subtree
        if (node->left) {
            currentPath.push_back('L');  // Add 'L' for left move
            if (findPaths(node->left, startValue, destValue, startPath, destPath, currentPath)) {
                return true;
            }
            currentPath.pop_back();  // Remove 'L' when backtracking
        }
        
        // Recursively search right subtree
        if (node->right) {
            currentPath.push_back('R');  // Add 'R' for right move
            if (findPaths(node->right, startValue, destValue, startPath, destPath, currentPath)) {
                return true;
            }
            currentPath.pop_back();  // Remove 'R' when backtracking
        }
        
        return false;  // Neither value found in this subtree
    }



int main(){
    vector<string>s{"2", "1"};
    TreeNode *root = TreeNode::makeTreeUsingStringElements(s);
    cout<<getDirections(root, 2, 1);
}