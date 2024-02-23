#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * Another graph problem where we have to find the min cost to reach the destination from the source,
 * only we have to be mindful of the number of steps to reach it from the destination.
*/
int main(){
}

class Node{
public:
    int nodeId;
    int cost;
    int steps;
    Node(int nodeId, int cost, int steps){
        this->nodeId = nodeId;
        this->cost = cost;
        this->steps = steps;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Node*>queue;
        vector<vector<int>>mat(n,vector<int>(n,-1));
        for(auto path: flights){
            mat[path[0]][path[1]]=path[2];
        }
        int minCost = 99999;
        unordered_map<int,int>vis;
        queue.push(new Node(src,0,-1));
        vis[src] = 0;
        while(!queue.empty()){
            Node *node = queue.front();
            queue.pop();
            if(node->steps>k)
            continue;
            if(node->nodeId==dst){
                minCost = min(minCost, node->cost);
                continue;
            }
            for(int i=0;i<n;i++){
                if(i!=node->nodeId && mat[node->nodeId][i]!=-1){
                    if(vis.find(i)==vis.end()){
                        vis[i] = node->cost + mat[node->nodeId][i];
                        queue.push(new Node(
                            i,
                            node->cost + mat[node->nodeId][i],
                            node->steps+1
                        ));
                    }
                    else{
                        if(vis[i]>node->cost+mat[node->nodeId][i]){
                            vis[i] = node->cost + mat[node->nodeId][i];
                            queue.push(new Node(
                            i,
                            node->cost + mat[node->nodeId][i],
                            node->steps+1
                            )
                            );
                        }
                    }
                }
            }
        }
        return minCost==99999?-1:minCost;
    }
};