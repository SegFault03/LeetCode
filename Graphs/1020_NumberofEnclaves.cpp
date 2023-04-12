#include<bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
        int count = 0, rows = grid.size(), cols = grid[0].size();
        for(int i = 1; i < rows-1; i++)
        {
            for(int j = 1; j < cols-1; j++)
            {
                if(grid[i][j]==1)
                {
                    int lcount = 0;
                    bool isValid = true;
                    stack<pair<int,int>>dfs;
                    dfs.push({i,j});
                    grid[i][j]=2;
                    while(!dfs.empty())
                    {
                        auto ele = dfs.top();
                        int ti = ele.first, tj = ele.second;
                        lcount++;
                        dfs.pop();
                        if(ti-1<0 || ti+1 == rows || tj-1<0 || tj+1 == cols)
                        {
                            isValid = false;
                            continue;
                        }
                        if(grid[ti-1][tj]==1){grid[ti-1][tj]=2; dfs.push({ti-1, tj});}                       
                        if(grid[ti+1][tj]==1){grid[ti+1][tj]=2; dfs.push({ti+1, tj});}                       
                        if(grid[ti][tj-1]==1) {grid[ti][tj-1]=2; dfs.push({ti, tj-1});}                       
                        if(grid[ti][tj+1]==1) {grid[ti][tj+1]=2; dfs.push({ti, tj+1});}
                    }
                    count += isValid?lcount:0;
                }
            }
        }
        return count;
    }

int main(){
    vector<vector<int>>grid{{1,1,1,1,1,1,1},
               {1,0,0,0,0,0,1},
               {1,0,1,1,1,0,1},
               {1,0,1,0,1,0,1},
               {1,0,1,1,1,0,1},
               {1,0,0,0,0,0,1},
               {1,1,1,1,1,1,1}};
    cout<<numEnclaves(grid);
}