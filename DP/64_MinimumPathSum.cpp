#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

//ACCEPTED SOLUTION
//DP SOLUTION

/*
Similar to problem: 746
There are only two ways to reach a tile: Either from the left tile, or from top tile. (As it says these are the only two ways we can move)
Hence, it follows that we should compare the two possible ways to reach the tile and choose the one that is minimum.
This way we can calculate the optimal cost for reaching every tile. 
cost[i][j] = min(cost[i-1][j], cost[i][j-1]) + grid[i][j]
*/
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long int>>dp(m,vector<long long int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1>=0 && j-1>=0)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                else if(i-1>=0)
                dp[i][j] = dp[i-1][j];
                else if(j-1>=0)
                dp[i][j] = dp[i][j-1];
                dp[i][j] += grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }

//GRAPH SOLUTION
/*
Works on the basis of the shortest path logic using BFS algorithm.
We travel to a node, we keep track of the total cost to reach that node, we travel to it's right and bottom neighbours.
If at any time, we travel to a node that has already been visited and find that the new cost is less than the cost it
took to travel to that node before, we update the cost, and push it to the queue again in order to update the cost
to reach its neighbours.

Note that this solution takes a longer time than DP because we're essentially revisiting nodes in order to update
their minimum costs, while in DP we visit a node (or a tile) only ONCE.
*/
int minPathSum2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        queue<pair<int,int>>queue;
        queue.push({0,0});
        vis[0][0] = 0;
        while(!queue.empty())
        {
            int r = queue.front().first;
            int c = queue.front().second;
            queue.pop();
            if(r==m-1 && c==n-1) continue;
            if(r+1<m)
            {
                if(vis[r+1][c]==-1 || vis[r+1][c]>vis[r][c]+grid[r][c])
                {
                    vis[r+1][c] = vis[r][c]+grid[r][c];
                    queue.push({r+1,c});
                }
            }
            if(c+1<n)
            {
                if(vis[r][c+1]==-1 || vis[r][c+1]>vis[r][c]+grid[r][c])
                {
                    vis[r][c+1] = vis[r][c]+grid[r][c];
                    queue.push({r,c+1});
                }
            }
        }
        return vis[m-1][n-1] + grid[m-1][n-1];
    }


int main(){
    vector<vector<int>>test{{1,2,3},{4,5,6}};
    cout<<minPathSum2(test);
}