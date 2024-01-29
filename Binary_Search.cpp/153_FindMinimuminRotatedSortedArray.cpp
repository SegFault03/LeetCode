#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * Obj is to find the first element where num[i-1]>num[i]<num[i+1] where i is the position of the element
 * Note that it MUST be the first element in the array when read in a left to right fashion, and not
 * necessarily the first element which is found that fulfils the condition.
*/
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return min(nums[0], nums[1]);
        int lb = 0, ub = n-1, mid, lp = nums[0], rp = nums[n-1], minE = 99999;  //we use lp and rp to compare mid element against them and get an idea
                                                                                // of where the min element could be
        while(ub>=lb) {
            mid = lb + (ub-lb)/2;
            if(nums[mid]>lp && nums[mid]<rp)                                    //already sorted, return first element
            return nums[0];
            else if(nums[mid]<lp && nums[mid]<=rp)                              //could be the min element, or maybe the min element lies to the left of it
            {
                minE = min(minE, nums[mid]);
                rp = nums[mid];
                ub = mid-1;
            }
            else                                                                //min element must lie to the right of it
            {
                lp = nums[mid];
                lb = mid+1;
            }
        }
        return minE; 
    }



int main(){
    vector<int>t = {1,2,4,5,6,7,0};
    cout<<findMin(t);
}