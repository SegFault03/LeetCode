//https://leetcode.com/problems/maximal-square/solutions/600149/python-thinking-process-diagrams-dp-approach/?envType=study-plan-v2&envId=dynamic-programming
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int maxSize = 0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(matrix[i-1][j-1]=='0') continue;
                dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                maxSize = maxSize < dp[i][j]? dp[i][j]: maxSize;
            }
        }
        return maxSize*maxSize;
    }

int main(){
    vector<vector<char>>test{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::cout<<maximalSquare(test);
}