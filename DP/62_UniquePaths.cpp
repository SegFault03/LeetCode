/*
DP problem to calculate the total number of ways to reach from one point of a grid to another.
Note: The robot can only move in 2 directions.
Thus, on any given tile on the grid, say i,j, the total number of ways to reach it would be grid[i-1][j] + grid[i][j-1]
This is a bit like the total number of ways to reach the i'th stair, except that was in 1D, this is in 2D.
Thus, grid[i][j] = grid[i-1][j] + grid[i][j-1]
*/

#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int uniquePaths(int m, int n) {
        if((m==1 && n==1) || (m==1 || n==1) ) return 1;                                     //only one way if its 1x1 or column or row vector
        vector<vector<long long int>>dp(m,vector<long long int>(n,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-1>=0)
                dp[i][j] = dp[i][j-1];
                if(i-1>=0)
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }


int main(){
}