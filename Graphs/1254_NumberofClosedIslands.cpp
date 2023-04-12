#include<bits/stdc++.h>
using namespace std;

int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        vector<vector<int>>map(rows, vector<int>(cols,0));
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                if(grid[i][j]==1 || map[i][j]==1 || map[i][j]==-1)
                continue;
                else
                {
                    bool valid = true;
                    stack<pair<int,int>>dfs;
                    dfs.push(make_pair(i,j));
                    while(!dfs.empty())
                    {
                        auto ele = dfs.top();
                        int ti = ele.first, tj = ele.second;
                        dfs.pop();
                        map[ti][tj]=1;
                        if(ti-1<0 || ti+1==rows || tj-1<0 || tj+1==cols)
                        {
                            valid = false;
                            continue;
                        }
                        if(map[ti-1][tj]==0 && grid[ti-1][tj]==0) dfs.push(make_pair(ti-1,tj));
                        if(map[ti+1][tj]==0 && grid[ti+1][tj]==0) dfs.push(make_pair(ti+1,tj));
                        if(map[ti][tj-1]==0 && grid[ti][tj-1]==0) dfs.push(make_pair(ti,tj-1));
                        if(map[ti][tj+1]==0 && grid[ti][tj+1]==0) dfs.push(make_pair(ti,tj+1));
                    }
                    if(valid) count++;
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
    cout<<closedIsland(grid);
}