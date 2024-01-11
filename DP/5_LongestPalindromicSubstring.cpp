#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
string longestPalindrome(string s) {
        int n = s.length();
        vector<int>dp(n,0);
        dp[0] = 1;
        string longestPalin = "";
        longestPalin += s[0];
        for(int i=1;i<n;i++)
        {
            int j=(i-dp[i-1]-1)<0?0:i-dp[i-1]-1;
            while(j<i)
            {
                if(s[i]==s[j])
                break;
                j++;
            }
            dp[i] = j==i?1:i-j+1;
            if(dp[i]==1) continue;
            string temp = s.substr(j,dp[i]);
            string temp2 = temp;
            reverse(temp.begin(),temp.end());
            if(temp2==temp)
            longestPalin = longestPalin.length()<temp.length()?temp:longestPalin;
        }
        return longestPalin;
    }


int main(){
    string test = "aacabdkacaa";
    cout<<longestPalindrome(test);
}