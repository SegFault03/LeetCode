//sol: https://leetcode.com/problems/minimum-cost-for-tickets/solutions/3349786/image-explanation-recursion-dp-dp-optimized-c-java-python/
#include<bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            int i7=i, i30=i;
            while(i7>=0 && days[i]-days[i7]<7) i7--;
            while(i30>=0 && days[i]-days[i30]<30) i30--;
            int ans = min(dp[max(0,i-1)]+costs[0],dp[max(0,i7)]+costs[1]);
            ans = min(ans,dp[max(0,i30)]+costs[2]);
            dp[i] = ans;
        }
        return dp[n-1];   
}

int main(){
    vector<int>t={1,4,6,7,8,20}, s={2,7,15};
    cout<<mincostTickets(t,s);
}