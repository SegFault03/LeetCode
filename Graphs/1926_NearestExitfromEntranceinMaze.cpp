#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
//Standard shortest path via BFS technique
int m, n;
    bool isBorder(int r, int c) {
        if(r==m-1 || r==0 || c==n-1 || c==0)
        return true;
        else
        return false; 
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size(), n = maze[0].size(); int minE = INT_MAX;
        vector<vector<int>>vis(m,vector<int>(n,99999));
        queue<pair<int,int>>queue;
        queue.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]] = 0;
        while(!queue.empty()) {
            int r = queue.front().first;
            int c = queue.front().second;
            queue.pop();
            if(r+1<m && maze[r+1][c]=='.' && (vis[r+1][c]==99999 || vis[r+1][c]>vis[r][c]+1)) {
                if(isBorder(r+1,c))
                minE = min(minE, vis[r][c]+1);
                else {
                    queue.push({r+1,c});
                    vis[r+1][c] = vis[r][c]+1;
                }
            }
            
            if(r-1>=0 && maze[r-1][c]=='.' && (vis[r-1][c]==99999 || vis[r-1][c]>vis[r][c]+1)) {
                if(isBorder(r-1,c))
                minE = min(minE, vis[r][c]+1);
                else {
                    queue.push({r-1,c});
                    vis[r-1][c] = vis[r][c]+1;
                }
            }
            
            if(c+1<n && maze[r][c+1]=='.' && (vis[r][c+1]==99999 || vis[r][c+1]>vis[r][c]+1)) {
                if(isBorder(r,c+1))
                minE = min(minE, vis[r][c]+1);
                else {
                    queue.push({r,c+1});
                    vis[r][c+1] = vis[r][c]+1;
                }
            }
            
            if(c-1>=0 && maze[r][c-1]=='.' && (vis[r][c-1]==99999 || vis[r][c-1]>vis[r][c]+1)) {
                if(isBorder(r,c-1))
                minE = min(minE, vis[r][c]+1);
                else {
                    queue.push({r,c-1});
                    vis[r][c-1] = vis[r][c]+1;
                }
            }
        }
        return minE==INT_MAX?-1:minE;
    }


int main(){
}