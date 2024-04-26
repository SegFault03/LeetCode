#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
/**
 * ACCEPTED SOLUTION
*/
using namespace std;


int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid.size()==1)
        return grid[0][0];
        vector<int>old(grid[0].size(), 0), curr(grid[0].size(), 0);
        int totMinCost = 99999, minCostRow, minCostEle;
        
        for(int i=0;i<grid[0].size();i++){
            old[i] = grid[0][i];
            curr[i] = grid[0][i];
            totMinCost = min(totMinCost, grid[0][i]);
        }
        cout<<totMinCost<<endl;
        for(int i=1;i<grid.size();i++){
            old = curr;
            minCostRow = 99999;
            for(int j=0;j<grid[0].size();j++){
                minCostEle = 99999;
                for(int k=0;k<grid[0].size();k++){
                    if(j != k){
                        minCostEle = min(minCostEle, grid[i][j] + old[k]);
                    }
                }
                curr[j] = minCostEle;
                cout<<"j= "<<j<<" minCostEle= "<<minCostEle<<endl;
                minCostRow = min(minCostEle, minCostRow);
            }
            totMinCost = minCostRow;
            cout<<"i = "<<i<<" totMinCost = "<<totMinCost<<endl;
        }
        return totMinCost;
    }

int main(){
}