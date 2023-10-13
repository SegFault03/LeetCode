/*
Similar to problem no.: 120, except this time it is a square.
Calcaulate the most optimal (minimum) cost to reach the next step.
We can travel to (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1) from (row,col)
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int minCost = INT_MAX;
        for(int i=0;i<n;i++)
        dp[0][i] = matrix[0][i];
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-1>=0)
                dp[i+1][j-1] = min(dp[i+1][j-1],dp[i][j]+matrix[i+1][j-1]);
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]+matrix[i+1][j]);
                if(j+1<n)
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+matrix[i+1][j+1]);
            }
        }
        for(int i=0;i<n;i++)
        minCost = minCost > dp[n-1][i]? dp[n-1][i]: minCost;
        return minCost;
    }


int main(){
}