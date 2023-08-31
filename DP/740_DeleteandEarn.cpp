#include<bits/stdc++.h>
//soln: https://leetcode.com/problems/delete-and-earn/solutions/109891/sharing-my-simple-straight-forward-java-o-n-solution-explanation-included/?envType=study-plan-v2&envId=dynamic-programming
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCPETED SOLUTION
int deleteAndEarn(vector<int>& nums) {
       int sum[10002] = {0}, maxS = -99999;
       for(int i=0;i<nums.size();i++)
       sum[nums[i]] += nums[i];
       for(int i=2;i<10002;i++)
       {
           sum[i] = max(sum[i-1], sum[i]+sum[i-2]);
           maxS = sum[i] > maxS? sum[i]: maxS;
       }
        return maxS;
    }


int main(){
    vector<int>test{2,2,3,3,3,4};
    cout<<deleteAndEarn(test);
}