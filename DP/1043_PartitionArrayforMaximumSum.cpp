#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * Obv, we need to consider multiple subarrays and while adding a new subarray, we'll have
 * to add it to the subarray giving the max sum -> Optimal substructure. Also, we might need to
 * recalculate a few subarrays -> Repeating subproblems. Thus it is a DP problem.
 * 
 * This is actually quite similar to the rod-cutting problem where we have to determine where
 * we make the cut (or split the array in this case) such that we can get the max value.
 * Consider an array: 1,15,7,9,10 with k = 3 and consider i=2(i.e, arr[i]=7). There are a bunch 
 * of subarrays we can make:
 * Consider only [1,15,7] for now. Let's see all the possible partitions:
 * [(1,15), (7)] -> 15*2 + 7 = 37 
 * [(1), ( 15, 7)] -> 1 + 15*2 = 31
 * [(1,15,7)] -> 15*3 = 45 -> max value.
 * Thus for the subarray [1,15,7], 45 is the max value and (1,15,7) is the desirable partition.
 * Now how many partitions can we make? Given in the question is the constraint k which tells
 * us that any subarray we make can be at most of length k. Thus we must consider all subarrays
 * of size 1...k for every i where 0<=i<=arr.length. We also store the max partition value for every
 * index i in a separate dp array.
 * 
 * Thus, dp[i] = max(dp[j-1]+max(arr[j..i])*(j-i+1)) for all 0<=i-k<=j<=i<=n
 * 
 * Demo example: https://imgur.com/kv4CcyQ
 * 
*/
int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0] = arr[0];
        for(int i=1;i<n;i++) {
            int maxE = i;
            for(int j=i;j>i-k && j>=0; j--) {
                maxE = arr[maxE]<arr[j]?j:maxE;
                dp[i] = max(dp[i], arr[maxE]*(i-j+1)+(j-1>=0?dp[j-1]:0));
            }
        }
        return dp[n-1];
    }


int main(){
    vector<int>t{1,15,7,9,2,5,10};
    cout<<maxSumAfterPartitioning(t, 3);
}