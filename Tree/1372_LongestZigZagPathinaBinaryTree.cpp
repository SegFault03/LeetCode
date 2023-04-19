#include<bits/stdc++.h>
#include "../headers/tree.h"
using namespace std;

/*
ALGO: DP TOP DOWN WITH MEMOIZATION/DIVIDE & CONQUER
1. Every time we move to a new node, we pass it the type of edge through which we arrived (left/right)
2. For each node, we find out the zig-zag length for both its left and right subtrees
3. We compare the max of the zig-zag length of left/right subtress to a max value, and update it as 
   necessary
4. While returning the value, we only return the zig-zag length of that subtree which is opposite to 
    the type of edge that is passed to it. E.g: if we moved from node 1 to node 2 through a left edge, then 
    we return the zig-zag length of the right subtree of node 2, and vice-versa.

Basically what we're doing is we're recording the zig-zag lengths of both the left/right subtrees of each
node, and depending upon the which edge (left/right) was used to traverse to the node, we return the zig-zag
length. This means we traverse the entire tree twice in DFS fashion. First, for finding the zig-zag length, 
and the second when we are returning the length. Based on the returned value, each node can then calculate
the new zig-zag length, and the process continues. For finding the length itself, a simple logic of counting
nodes in a tree is used. The zig-zag pattern required is actually replicated by returning only the zig-zag value
of that subtree which is opposite to the edge-type that was used to traverse to that node. This means node 1, 
which has node 2 as its right child will receive the zig-zag length of node 2's left subtree, similarly
node 2, which has node 3 as its left-child, will receive the zig-zag length of node 3's right subtree.
so the pattern goes a bit like this:
node1 <- left <- node2 <- right <- node3 <- left <- node4 and so on.                                         
*/

int zigZagLength(TreeNode *root, int p, int *maxL)          //p: 0 = root, 1 = left, 2 = right
    {
        if(root==nullptr) return 0;                     
        int r = 0, l = 0;
        r = 1 + zigZagLength(root->right, 2, maxL);         //zig-zag length of right subtree
        l = 1 + zigZagLength(root->left, 1, maxL);          //zig-zag length of left subtree
        *maxL = *maxL<max(r,l)?max(r,l):*maxL;              //compare zig-zag lengths to max 
        return p==1?r:(p==2?l:max(r,l));                    //return the zig-zag length of the opposite type
    }

    int longestZigZag(TreeNode* root) {
        int max = 0;
        int temp = zigZagLength(root,0,&max);
        return max-1;                                       //no. of edges = no. of nodes - 1
    }

int main(){
}