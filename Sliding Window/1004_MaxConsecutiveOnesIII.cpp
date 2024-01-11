#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size(), maxL = INT_MIN, rem = k, ws = 0;
        while(right<n){
            if(nums[right]==0){
                if(rem==0){
                    ws = right-left;
                    maxL = ws>maxL?ws:maxL;
                    while(nums[left]==1 && left<=right)
                    left++;
                    left++;
                }
                else
                rem--;
            }
            right++;
        }
        ws = right-left;
        maxL = ws>maxL?ws:maxL;
        return maxL;
    }


int main(){
    vector<int>ans{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout<<longestOnes(ans,3);
}