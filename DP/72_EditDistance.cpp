#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLN.
*/
int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<m+1;i++) dp[0][i] = i;
        for(int i=0;i<n+1;i++) dp[i][0] = i;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[j-1]!=word2[i-1])
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
                else
                dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }


int main(){
}