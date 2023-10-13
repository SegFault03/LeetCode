//See editorial for more info: https://leetcode.com/problems/longest-palindromic-subsequence/editorial/?envType=study-plan-v2&envId=dynamic-programming
/*The key idea here is to find the longest palindromic subsequence among all possible lengths of substrings.
In other words, we have to find LCS in all possible substrings of lengths 1,2,3,4, etc.
The key logic of finding out the lcs is this:

(i)For a given string, if its first char and last char is same, lcs(first, last) = 2 + lcs(first+1, last-1). 
In other words, add 2 to the lcs for the substring(first+1, last-1)

(ii)If first char != last char, then we'll have to look for all possible arrangements of the string and
find the max lcs among those arrangements. We'll start first by considering one arrangement where we delete
the first char and take the rest, and another arrangement where we delete the last char and take the rest.This 
is because since last char != first char, they cannot possible be part of the palindromic subsequence.
Thus in this case, lcs(first, last) = max(lcs(first, last-1), lcs(first+1, last))

The final answer will be lcs(0, s.len-1)
Adopting a bottom-up apprach, we can start first by finding the lcs of substrings of length 1, then 2, then 3, and so on.
This way we can cover all possible subsequences that are possible in the given string.
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int longestPalindromeSubseq(string s) {
        int l = s.length(), i, j;
        vector<vector<int>>dp(l,vector<int>(l,0));
        for(i=0;i<l;i++)                                        //filling lcs of substrings of length 1
        dp[i][i] = 1;
        int c = l-1;
        while(c>0)                                              //The dp matrix will be filled diagonally
        {   for(i=0;i<c;i++)
            {
                j = i+l-c;
                int a=1, b=1;
                if(s[i]==s[j])                                  //first char = last char
                {
                    if(i+1<l && j-1>=0)
                    dp[i][j] = 2 + dp[i+1][j-1];                //add 2 to the lcs of substring(i+1,j-1)
                }
                else
                {
                    if(i+1<l)
                    a = dp[i+1][j];                             //find max lcs of right part
                    if(j-1>=0)
                    b = dp[i][j-1];                             //find max lcs of left part
                    dp[i][j] = max(a,b);                        
                }
            }
            c--;
        }
        return dp[0][l-1];
    }

int main(){
    cout<<longestPalindromeSubseq("axbklbma");                  //ans: 5 ->abkba or ablba 
}