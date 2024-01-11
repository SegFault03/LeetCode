#include<bits/stdc++.h>
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
/*
We have to consider all possible subsequences. Naturally, this is a DP problem.
If we consider a bottom-up approach:
-> For i in arr[0..n],
    -> We check if arr[i]-difference is present in arr[0..i-1]. This is because there can only
    be one possible number that can have a difference as given with arr[i].
    E.g, if arr[i]=5, and difference given = 2, then we only have to check if 5-2 = 3 was
    present in the array elements that we've already encountered.
    -> If true, we memoize the length of the subsequence as dp[i] = 1+dp[j],
    where arr[j]=arr[i]-dp and 0<=j<i
    -> We update maxLength of the subsequence for each i
One possible way of checking for a given number in the array is obv using a for loop,
but to minimize time complexity, we can use a hashmap instead, and store the elements that have already 
been encountered as keys, with the subsequence length upto those elements as their values.
This way, we can check if the element we are searching for is present or not in constant time.
*/
int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;                                   //key = array elements, value = subsequence length upto that element
        int n = arr.size(), maxL = 1;
        dp[arr[0]]=1;
        for(int i=1;i<n;i++){
            if(dp.find(arr[i]-difference)!=dp.end())                //check if the required element that is equal to arr[i]-difference is present in the array traversed so far
            dp[arr[i]] = 1+dp[arr[i]-difference];                   //if true, add 1 to subsequence length and update dp[arr[i]]
            else
            dp[arr[i]] = 1;
            maxL = maxL<dp[arr[i]]?dp[arr[i]]:maxL;
        }
        return maxL;
    }

int main(){
    vector<int>test{VectorParser::oneDArrayParser("[4,12,10,0,-2,7,-8,9,-9,-12,-12,8,8]")};
    cout<<longestSubsequence(test, -2);
}