#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length(), i, j;
        vector<vector<int>>dp(l2+1, vector<int>(l1+1,0));
        for(i=1;i<l2+1;i++)
        {
            for(j=1;j<l1+1;j++)
            {
                if(text1[j-1]==text2[i-1])
                dp[i][j] = dp[i-1][j-1]+1;
                else
                {
                    dp[i][j] = max(
                        max(
                            dp[i][j-1],
                            dp[i-1][j]
                        ),
                        dp[i-1][j-1]
                    );
                }
            }
        }
        return dp[l2][l1];
    }


int main(){
    cout<<longestCommonSubsequence("abcde", "ace");
}