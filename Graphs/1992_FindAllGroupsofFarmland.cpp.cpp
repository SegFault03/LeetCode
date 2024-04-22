#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;


    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        queue<pair<int,int>> queue; // Queue to store cells to explore
        vector<vector<int>> ans;    // Stores coordinates of farmland groups

        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1) // Check if current cell is farmland (1)
                {
                    pair<int,int> ul = {i, j}, lr = {i,j}; // Initialize group boundaries
                    queue.push({i,j});                  // Add current cell to explore
                    land[i][j] = 2;                      // Mark cell as visited (2)

                    while(!queue.empty()){
                        int r = queue.front().first;
                        int c = queue.front().second;
                        queue.pop();

                        lr = max(lr, {r,c}); // Update group's lower right corner 

                        // Explore adjacent cells (up, down, left, right)
                        if(r+1<land.size() && land[r+1][c]==1 && land[r+1][c] != 2) { 
                            land[r+1][c] = 2; // Mark as visited and add to queue
                            queue.push({r+1,c});
                        }
                        if(r-1>=0 && land[r-1][c]==1 && land[r-1][c] != 2) {
                            land[r-1][c] = 2;
                            queue.push({r-1,c});
                        }
                        if(c+1<land[0].size() && land[r][c+1]==1 && land[r][c+1] != 2) {
                            land[r][c+1] = 2;
                            queue.push({r,c+1});
                        }
                        if(c-1>=0 && land[r][c-1]==1 && land[r][c-1] != 2) {
                            land[r][c-1] = 2;
                            queue.push({r,c-1});
                        }
                    }
                    ans.push_back(vector<int>{ul.first, ul.second, lr.first, lr.second}); // Add group info to results
                }
            }
        }
        return ans;
    }



int main(){
    string s = "[[1,0,0],[0,1,1],[0,1,1]]";
    vector<vector<int>>t = VectorParser::twoDArrayParser(s);
    vector<vector<int>>ans = findFarmland(t);
    VectorParser::printtwoDArray(ans);
}