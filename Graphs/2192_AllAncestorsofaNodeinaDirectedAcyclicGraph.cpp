#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLUTION
Intuition and Logic:

This solution uses a Depth-First Search (DFS) approach to find all ancestors of each node in a Directed Acyclic Graph (DAG).

Key Ideas:
1. Reverse the edges: We build an adjacency list with reversed edges. This way, traversing the graph gives us ancestors instead of descendants.
2. DFS with memoization: We use DFS to traverse the graph, storing computed ancestors to avoid redundant calculations.
3. Set for uniqueness and sorting: We use a set to store ancestors, which automatically handles uniqueness and sorting.

Algorithm walkthrough:
1. Build the reversed adjacency list.
2. For each node, if not processed:
   a. Perform DFS from that node.
   b. During DFS, add immediate parents and recursively their ancestors.
3. Convert the set of ancestors to a vector for the final output.

Example:
Consider the graph: n = 4, edges = [[0,1], [0,2], [1,3], [2,3]]

Reversed adjacency list:
1 -> 0
2 -> 0
3 -> 1, 2

DFS process:
- Start with node 3:
  - Add 1 to ancestors of 3
  - Recursively process 1:
    - Add 0 to ancestors of 1
    - Add 0 to ancestors of 3
  - Add 2 to ancestors of 3
  - Recursively process 2:
    - Add 0 to ancestors of 2
    - 0 is already in ancestors of 3, so no change
- Process node 2 (already done in previous step)
- Process node 1 (already done in previous step)
- Process node 0 (no ancestors)

Final result: [[],[0],[0],[0,1,2]]

Time Complexity: O(N^2 + E) in worst case, where N is the number of nodes and E is the number of edges.
Space Complexity: O(N^2 + E) in worst case, due to the storage of ancestors and the adjacency list.

*/

class Solution {
public:
    // DFS function to find ancestors of a given vertex
    set<int> DFS(int vertex, unordered_map<int, vector<int>>& adjList,
                 vector<bool>& isProcessed, unordered_map<int, set<int>>& ancestors) {
        // If this vertex is already processed, return its ancestors
        if (isProcessed[vertex]) return ancestors[vertex];

        // For each parent of the current vertex
        for (auto parent : adjList[vertex]) {
            // Add the immediate parent to the ancestors set
            ancestors[vertex].insert(parent);
            // Recursively get ancestors of the parent
            set<int> parentAncestors = DFS(parent, adjList, isProcessed, ancestors);
            // Add all ancestors of the parent to the current vertex's ancestors
            ancestors[vertex].insert(parentAncestors.begin(), parentAncestors.end());
        }

        // Mark this vertex as processed
        isProcessed[vertex] = true;
        return ancestors[vertex];
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, set<int>> ancestors;
        unordered_map<int, vector<int>> adjList;
        vector<bool> isProcessed(n, false);

        // Build the reversed adjacency list
        for (auto edge : edges) {
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> ans(n);

        // Process ancestors for each vertex
        for (int i = 0; i < n; i++) {
            if (!isProcessed[i]) {
                DFS(i, adjList, isProcessed, ancestors);
            }
            // Convert set to vector for the final answer
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return ans;
    }
};


