#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
/**
 * We have to count the longest chain of 1s, one zero is ok, but once we encounter two zeroes, we should break the chain,
 * update length, and set the begining of the chain AFTER the position of the first zero that we encountered (This will help
 * us maximize the length of the chain).
*/
int longestSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int zeroPos = -1, maxL = 0, lp = 0, tempL, i;
        bool hasZero = false;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(hasZero){
                    tempL = (i-lp)-1;
                    maxL = tempL>maxL?tempL:maxL;
                    lp = zeroPos+1;                                     //set left pointer to index one more than the position of the first zero
                }
                else
                hasZero = true;                                         //save the fact that we've seen one zero and store the index of the first zero
                zeroPos = i;                                            //save the position of the first zero
            }
        }
        tempL = (i-lp)-1;
        maxL = tempL>maxL?tempL:maxL;
        return maxL;
    }

int main(){

}