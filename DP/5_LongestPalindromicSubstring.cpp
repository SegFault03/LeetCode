#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION

//Much easier but slower solution
/**
 *  * An important concept is that if s[i..j] is a palindrome, then s[i-1...j+1] is also a palindrome IF s[i-1]=s[j+1].
 * This means if we can somehow store the length of s[i..j], all we have to do is check if s[i-1]=s[j+1]. IF true, we simply
 * add 2 to the length of s[i..j] that is j-i+1.
 * 
 * We can do this by checking palindromes for all possible substrings, starting from the smallest
 * ones (length=1) to larger ones (upto length = s.length). So, first we check if s[0..0], s[1..1]...s[l-1..l-1]
 * are palindromes, then we check if s[0..1], s[1..2], s[2..3]....s[l-2..l-1] are palindromes
 * and similarly for s[0..2], s[1..3], etc. [Note: s[i..j] means a substring starting from
 * s[i] upto s[j], inclusive, with a length of j-i+1]. 
 * The above approach of checking for palindromes of all possible substrings allow us to store the length of some substring
 * that is a palindrome, so that later on, we don't need to recheck it. It is also important that we start by checking
 * the smallest substrings first, because otherwise while checking the larger substrings, we might have to recompute for the
 * smaller substrings.
 * 
 * Thus, we construct a dp table where dp[i][j] = length of the palindromic substring s[i..j], or 0 if s[i..j] is not a palindrome
 * 
*/
string longestPalindrome2(string s) {
        if(s.length()==1) return s.substr(0,1);
        int l = s.length(), maxL = 1, c = 0;
        vector<vector<int>>dp(l,vector<int>(l,0));
        pair<int,int>ind = {0,0};
        while(c<l){
            for(int i=0;i+c<l;i++)
            {
                //when length is 1
                if(i==i+c)
                dp[i][i] = 1;
                else if(s[i]==s[i+c])
                {
                    //when length is 2
                    if(i+1==i+c)
                    dp[i][i+1] = 2;
                    else 
                    dp[i][i+c] = dp[i+1][i+c-1]>0?2+dp[i+1][i+c-1]:0; 
                }
                else
                dp[i][i+c] = 0;
                if(dp[i][i+c]>maxL){
                    maxL = dp[i][i+c];
                    ind.first = i;
                    ind.second = i+c;
                }
            }
            c++;
        }
        return s.substr(ind.first, ind.second-ind.first+1);    
    }


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
    // string test = "aacabdkacaa";
    cout<<longestPalindrome2("aacabdkacaa");
}