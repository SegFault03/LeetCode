#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * Accepted soluton
 * This is a DP problem (Most counting problems generally are)
 * Proof:
 * ->Optimal substructure property:
 * Consider the string "123"
 * "12" alone can be decoded as 1 2 or 12 (2 ways)
 *  So for 123, decoding 3 separately, we can decoded 123 as 1 2 3 or 12 3 (2 ways) = ways of decoding "12"
 *  Again decoding 23 separately, it can be decoded as 1 23 (1 way) = ways of decoding "1"
 * Thus it is quite clear that for decoding a larger string, we need to find all the ways of decoding a smaller string
 * that is a substring of the larger string.
 * 
 * ->Overlapping subproblems
 * Extending the above example, consider the string "1232"
 * For decoding "123", we need to find all the ways to decode "12".
 * Again, for decoding "1232", we again need to ways to decode "12" (when we consider 32 separately)
 * Thus, the same subproblem needs to be repeatedly solved.
 * 
 * Solution:
 * There are two cases we have to consider:
 * Whether s[i] can be decoded by itself (always true)
 * In this case total no. of ways = dp[i] = dp[i-1] 
 * 
 * Whether s[i] and s[i-1] can be decoded by itself
 * Only possible if 10<=substring(s[i-1],s[i+1])<=26
 * In this total no. of ways = dp[i-2]
 * 
 * Thus recursive reln:
 * dp[n] = dp[n-1]*1 + dp[n-2]*k(n)
   where k(n) = 1, if 10<=concat(n,n-1)<=26, 0 otherwise.  
*/
int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,0);
        dp[0] = s[0]-48>0?1:0;
        for(int i=1;i<n;i++){
            dp[i] = s[i]-48>0?dp[i-1]:0;
            string k = s.substr(i-1,2);
            int temp = std::stoi(k);
            if(temp>=10 && temp<=26)
            dp[i]+=(i-2)>=0?dp[i-2]:1;
        }
        return dp[n-1];
    }

int main(){
    string test = "06";
    cout<<numDecodings(test);
}