#include<bits/stdc++.h>
using namespace std;
/*
NOTES: This problem uses a greedy strategy to solve the problem along with DFS tree-traversal technique.
Since every search begins from the root (0 in this case), there is only one path to reach any node 
(which means we don't and can't evaluate any other search paths), and the minimum time to collect all 
aplles starting from the root is to find the number of edges to which a node containing an apple is 
present and hence multiply it by 2. This is because time to travel each edge = 1, and the edge has 
to be traversed twice (once for reaching the node, once for returning).

The algorithm is quite simple: Start a DFS search from the root node, every node returns the number of 
edges to be traversed in its subtree (including itself). The final answer is the number of edges returned
by the root node * 2
*/
int findMinTime(int node, unordered_map<int,vector<int>> &adjMap, vector<bool>& hasApple,unordered_map<int,int> &vis)
    {
        if(node==0)                                 //root node
        {
            vis[0]=1;
            int s=0;
            for(auto i: adjMap[node])
            s+=findMinTime(i,adjMap,hasApple,vis);
            return s;
        }
        if(adjMap[node].size()==0)
        return hasApple[node]?1:0;
        else
        {
            vis[node]=1;
            int s=0;
            for(auto i: adjMap[node])               //search its subtree
            {
                if(vis[i]==0)
                s+=findMinTime(i,adjMap,hasApple,vis);
            }
            return (s>0)?1+s:(hasApple[node])?1:0;  //return count of edges
        }
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adjMap;
        unordered_map<int,int>vis;
        for(auto i: edges)
        {
            if(adjMap.find(i[0])==adjMap.end())
            adjMap[i[0]]={i[1]};
            else
            adjMap[i[0]].push_back(i[1]);
            if(adjMap.find(i[1])==adjMap.end())
            adjMap[i[1]]={i[0]};
            else
            adjMap[i[1]].push_back(i[0]);
        }
        int no_of_edges = findMinTime(0,adjMap,hasApple,vis);
        return no_of_edges*2;
    }

int main(){
    vector<vector<int>>edges{{0,2},{1,2},{0,3}};
    vector<bool>hasApple{false,true,false,false};
    cout<<minTime(4,edges,hasApple);
}