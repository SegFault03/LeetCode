/*
This is quite a simple problem showing how to find the shortest distance between any two given points using BFS
Here, in the given question, we are given a binary array, and we have to find the shortest distance between the starting
index (arr[0][0]) and the ending index (arr[rows-1][cols-1]) subject to 2 constraints:
(i) All of the indices lying on the path must be filled with zeroes
(ii) We can travel in all possible 8 directions
Since this requires us to find the shortest path possible between 2 given points, we can use BFS, as that will allow us
to explore all possible paths and update distances simultaneously and reject the longer paths. This is better than
the DFS approach where we explore all possible paths one by one, thus taking a longer time to complete.

The core logic behind finding the shortest path involves keeping track of the distance of each index from the starting index,
and a re-updation process where we update their distances only if we find a shorter way to reach these indices.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

    void check(int row, int col, int curr, queue<pair<int,int>> &queue,vector<vector<int>> &vis, vector<vector<int>>& grid )
    {
        if(grid[row][col]==1) return;                                               //Check if the given index has a 0, reject it otherwise
        if(vis[row][col]==-1 || vis[row][col]> curr+1)                              //CORE LOGIC: Push an index only if it has never been visited before (-1)...
        {                                                                           //... or the current way of travelling to that index is shorter than...        
            queue.push({row,col});                                                  //..what was previously recorded (vis[row][col]> curr+1). This is bcuz...
            vis[row][col] = curr+1;                                                 //...if we find a shorter way to travel to particular index, then the distances...
        }                                                                           //...of its neighbouring indices will have to be re-updated as well!
    }                                                                               //We can guarantee that the queue will eventually be empty (no infinite loop)
                                                                                    //bcuz at some point we will have found the shortest distance for travelling
                                                                                    //to each index, thus no more indices will be pushed into the queue.

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));                                //Distance matrix to keep track of distance of each index from arr[0][0]
        queue<pair<int,int>>queue;
        if(grid[0][0]==1) return -1;                                                //The staring index is 1, no path possible
        queue.push({0,0});                                                          //Push the first index              
        vis[0][0] = 1;                                                              //Update distance matrix to 1 (Note: shd be 0, but here we count the indexes)
        while(!queue.empty())                                                       //Standard BFS implementation
        {
            pair<int,int> r = queue.front();
            queue.pop();
            int row = r.first, col = r.second;
            int curr = vis[row][col];                                               //Record the distance of the popped index from arr[0][0]                     

            if(row-1>=0) check(row-1,col,curr,queue,vis, grid);                     //check the validity of the 8 neighbouring indices...
            if(row-1>=0 && col+1<n) check(row-1,col+1,curr,queue,vis, grid);        //(contd)..if valid, call check(...)
            if(col+1<n) check(row,col+1,curr,queue,vis, grid);
            if(row+1<m && col+1<n) check(row+1,col+1,curr,queue,vis, grid);
            if(row+1<m) check(row+1,col,curr,queue,vis, grid);
            if(row+1<m && col-1>=0) check(row+1,col-1,curr,queue,vis, grid);
            if(col-1>=0) check(row,col-1,curr,queue,vis, grid);
            if(row-1>=0 && col-1>=0) check(row-1,col-1,curr,queue,vis, grid);
        }
        return vis[m-1][n-1];                                                       //Return the distance of the last index [arr(row-1,col-1) from arr(0)(0)]
    }

int main(){
    vector<vector<int>>test{{0,1,0,0,1},{0,0,0,1,0},{1,1,0,0,1},{1,0,0,0,1},{1,0,0,1,0}};
    cout<< shortestPathBinaryMatrix(test);
}