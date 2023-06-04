/*
BFS Approach to find the number of connected components in a graph.
E.g: Consider a graph - 1---2---3  4--5  6
There are 3 connected components in this graph -> 3 provinces
This can be solved using a standard BFS approach.
i. We choose a random unvisited node and start implementing BFS on it
ii. At the end of the search, we increment a counter keeping track of connected components to 1 (as the first connected component has been found)
iii. We repeat i and ii for all unvisited nodes.
ACCEPTED SOLUTION
*/
#include<bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int>queue;
        vector<int>vis(isConnected.size(),-1);
        int total = 0;
        for(int i=0;i<vis.size();i++)                               //Only visit yet-to-be visited nodes, as only they can form new connected components
        {
            if(vis[i]==-1)
            {
                queue.push(i);
                vis[i] = 1;
                while(!queue.empty())
                {
                    int root = queue.front();
                    queue.pop();
                    for(int j=0;j<isConnected.size();j++)
                    {
                        if(isConnected[root][j]==1 && vis[j]!=1)
                        {
                            vis[j]=1;
                            queue.push(j);
                        }
                    }
                }
                total++;                                            //All the nodes that form a connected component have been found, increment counter to 1
            }
        }
      return total;      
    }

int main(){
}