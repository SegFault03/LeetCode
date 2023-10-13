#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
/*
Classic 2-pointer problem. Although the goal is to maximize the number of operations, the truth is that we 
will always have a fixed number of operations to perform. This is because after each operation, both the elements 
of the array are deleted, so we cannot selectively choose which one to delete, in hope to reuse the non-deleted
element in the future. Thus, we simply have to find out the total number of pairs that add up to the target, using
2 pointer strat.
*/
int maxOperations(vector<int>& nums, int k) {
        if(k<2) return 0;
        long long int n = nums.size(), count = 0;
        int lp = 0, rp = n-1;
        sort(nums.begin(),nums.end());
        while(lp<rp){
            long long int s = nums[lp]+nums[rp];
            if(s==k)
            {
                count++;
                lp++;
                rp--;
            }
            else if(s>k)
            rp--;
            else
            lp++;
        }
        return count;
    }


int main(){
}