#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
/**
 * This is an extension of DP\5_LongestPalindromicSubstring.cpp with the additional count
 * var to store the no. of palindromes.
*/
 int countSubstrings(string s) {
        if (s.length() == 1)
            return 1;
        int l = s.length(), count=0, c = 0;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        while (c < l) {
            for (int i = 0; i + c < l; i++) {
                if (i == i + c)
                    dp[i][i] = 1;
                else if (s[i] == s[i + c]) {
                    if (i + 1 == i + c)
                        dp[i][i + 1] = 2;
                    else
                        dp[i][i + c] = dp[i + 1][i + c - 1] > 0
                                           ? 2 + dp[i + 1][i + c - 1]
                                           : 0;
                } else
                    dp[i][i + c] = 0;
                if (dp[i][i + c] > 0) 
                count++;
            }
            c++;
        }
        return count;
    }



int main(){
}