#include<bits/stdc++.h>
using namespace std;
//TODO UNFINISHED
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size()+1, m = *max_element(endTime.begin(),endTime.end());
    int dp[n][m];
    memset(dp, 0, sizeof(dp)); 
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(endTime[i-1]>j+1)
            dp[i][j] = dp[i-1][j];
            else if(endTime[i-1]==j+1)
            {
                if(dp[i-1][startTime[i-1]-1]+profit[i-1]>dp[i-1][j])
                dp[i][j] = dp[i-1][startTime[i-1]-1]+profit[i-1];
                else
                dp[i][j] = dp[i-1][j];
            }
            else
            dp[i][j] = dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

int main(){
    vector<int>sp={1,2,3,4,6}, ep={3,5,10,6,9}, p={20,20,100,70,60};
    cout<<jobScheduling(sp,ep,p);
}