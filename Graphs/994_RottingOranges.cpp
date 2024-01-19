#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
/**
 * This is a modification of the shortest path BFS since there are multiple sources from where the search
 * will start. The core logic remains the same: update nodes as visited, track the distance of a node
 * from the source, and re-visit previously visited nodes if they can be reached quicker (have smaller di
 * stances from a new source). Two ways of tackling the multiple source problem: Run BFS once for each source,
 * update each node with the min distance from ANY source, OR push all the sources all at once 
 * and run BFS once. Each node again is updated with the min distance from ANY source.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), orange = 0, maxT = 0;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        vector<pair<int,int>>rotten;
        queue<pair<int,int>>queue;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2)
                rotten.push_back({i,j});
                if(grid[i][j]!=0)
                orange++;
            }
        }
        for(int i=0;i<rotten.size();i++) {
            queue.push({rotten[i].first, rotten[i].second});
            vis[rotten[i].first][rotten[i].second] = 0;
            while(!queue.empty()) {
                int r = queue.front().first;
                int c = queue.front().second;
                queue.pop();
                if(r+1<m && grid[r+1][c]!=0 && (vis[r+1][c]==-1 || vis[r+1][c]>vis[r][c]+1))
                {
                    vis[r+1][c] = vis[r][c]+1;
                    queue.push({r+1,c});
                }
                
                if(r-1>=0 && grid[r-1][c]!=0 && (vis[r-1][c]==-1 || vis[r-1][c]>vis[r][c]+1))
                {
                    vis[r-1][c] = vis[r][c]+1;
                    queue.push({r-1,c});
                }
                
                if(c+1<n && grid[r][c+1]!=0 && (vis[r][c+1]==-1 || vis[r][c+1]>vis[r][c]+1))
                {
                    vis[r][c+1] = vis[r][c]+1;
                    queue.push({r,c+1});
                }
                
                if(c-1>=0 && grid[r][c-1]!=0 && (vis[r][c-1]==-1 || vis[r][c-1]>vis[r][c]+1))
                {
                    vis[r][c-1] = vis[r][c]+1;
                    queue.push({r,c-1});
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]!=0)
                {
                    if(vis[i][j]==-1)
                    return -1;
                    else
                    maxT = max(maxT, vis[i][j]);
                }
            }
        }
        return maxT;
    }
};


int main(){
}