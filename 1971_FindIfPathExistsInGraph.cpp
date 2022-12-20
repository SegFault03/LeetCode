#include<bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if(n==1)
        return true;
    unordered_map<int,vector<int>>edgemap;
    for(int i=0;i<edges.size();i++)
    {
        if(edgemap.find(edges[i][0])==edgemap.end())
        {
            vector<int>temp{edges[i][1]};
            edgemap[edges[i][0]]=temp;
        }
        else
        edgemap[edges[i][0]].push_back(edges[i][1]);

        if(edgemap.find(edges[i][1])==edgemap.end())
        {
            vector<int>temp{edges[i][0]};
            edgemap[edges[i][1]]=temp;
        }
        else
        edgemap[edges[i][1]].push_back(edges[i][0]);
    }

    stack<int>stack;
    unordered_map<int,int>visited;
    stack.push(source);
    while(!stack.empty())
    {
        int v = stack.top();
        visited[v]=1;
        stack.pop();
        for(int e=0;e<edgemap[v].size();e++)
        {
            if(edgemap[v][e]==destination)
            return true;
            if(visited[edgemap[v][e]]==0)
            stack.push(edgemap[v][e]);
        }
    }
    return false;
}

int main(){
    vector<vector<int>>edges{{0,1},{1,2},{2,0}};
    cout<<validPath(3,edges,0,3);
}