#include<bits/stdc++.h>
using namespace std;
/*
NOTES: Logic is pretty simple: 
Perform a DFS starting from both the nodes, recording the distance of each node from the 
starting node, and store them separately.
Compare the nodes visited and the corresponding distances to get the ans.
*/
void dfs(vector<int>& edges, int node, unordered_map<int,int> &vis)
    {
        int root;
        stack<int>stack;
        stack.push(node);
        vis[node]=0;
        while(!stack.empty())
        {
            root = stack.top();
            stack.pop();
            if(edges[root]!=-1 && vis.find(edges[root])==vis.end())
            {
                vis[edges[root]] = vis[root] + 1;       //update distance from the root node
                stack.push(edges[root]);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int>vis1, vis2;
        dfs(edges,node1,vis1);
        dfs(edges,node2,vis2);
        int min = 99999,node=-1;
        for(auto [key,value] : vis1)                   //compare the distances of each node visited
        {
            //only compare distances of those nodes that are reachable from both nodes
            if(vis2.find(key)!=vis2.end() && max(vis1[key],vis2[key])<=min)
            {
                if(min == max(vis1[key],vis2[key]))
                node = node>key?key:node;
                else
                node = key;
                min = max(vis1[key],vis2[key]);
            }
        }
        return node;
    }

int main(){
    vector<int>test{1,4,3,4,5,2,0};
    cout<<closestMeetingNode(test,0,2);
}