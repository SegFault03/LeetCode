/*
Standard algorithm for finding the number of connected components in a given graph.

Intuition: Start DFS/BFS on a node yet to be visited, visit all of its neighbouring nodes in
BFS/DFS fashion, mark them all as visited. Increment count by 1 when search is complete.
Do this for the remaining unvisited nodes.
*/

#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), num_islands = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>queue;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                    queue.push({i,j});
                    vis[i][j]=1;
                    while(!queue.empty())
                    {
                        int r = queue.front().first;
                        int c = queue.front().second;
                        queue.pop();
                        //r,c-1
                        if(c-1>=0 && (grid[r][c-1]=='1' && vis[r][c-1]!=1)) 
                        {
                            vis[r][c-1]=1;
                            queue.push({r,c-1});
                        }
                        
                        //r-1,c
                        if(r-1>=0 && (grid[r-1][c]=='1' && vis[r-1][c]!=1)) 
                        {
                            vis[r-1][c]=1;
                            queue.push({r-1,c});
                        }
                        
                        //r,c+1
                        if(c+1<n && (grid[r][c+1]=='1' && vis[r][c+1]!=1)) 
                        { 
                            vis[r][c+1]=1;
                            queue.push({r,c+1});
                        }
                        
                        //r+1,c
                        if(r+1<m && (grid[r+1][c]=='1' && vis[r+1][c]!=1)) 
                        {
                            vis[r+1][c]=1;
                            queue.push({r+1,c});
                        }
                    }
                    num_islands++;          //increment count as 1 connected component has been fully traversed
                }
            }
        }
        return num_islands;
    }


int main(){
    vector<vector<char>>test{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<numIslands(test);
}