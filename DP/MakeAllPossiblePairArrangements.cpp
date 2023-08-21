/*
DP problem which has overlapping subproblems. See https://leetcode.com/discuss/general-discussion/1349122/friends-pairing-problem for img
Essentially, for any n, we only have 2 choices:
(i) Either stay alone
(ii) Join a group
In the first case, the total possible combinations would be f(n-1), with us being the only constant in each case
In the second case, we can pair up with any of the n-1 people, and the total possible arrangements can be n-1 * f(n-2)
Thus the recursive relation forms: f(n) = f(n-1) + (n-1) * f(n-2)

For eg.: consider {1,2,3,4} where I am 1
I can either stay alone:
{1,[2,3,4]} where [2,3,4] is the all possible combinations of {2,3,4}
Or I pair up:
{[1,2],[3,4]}
{[1,3],[2,4]}
{[1,4],[2,3]}
*/

#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int countFriendsPairings(int n) 
    { 
        if(n==1) return 1;
        if(n==2) return 2;
        unsigned long long int tn_1 = 1, tn_2 = 2, ans = 1, i = 1, mod = 1e9+7;         //The results will be really big, we only need the last two terms
        while(i<=n)                                                                     //Bottom up approach
        {
            ans = (tn_1 + (i-1)*tn_2)%mod;                                              
            tn_2 = tn_1;    
            tn_1 = ans;
            i++;
        }
        return ans%mod;
    }

int main(){
}