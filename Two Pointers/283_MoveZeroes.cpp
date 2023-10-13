#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lp = 0, rp = -1;                            //lp -> index of the rightmost zero before which all elements are non-zero
        while(lp<n && rp<n)                             //rp -> index of the rightmost non-zero before which all elements are zero (upto lp)
        {                                               //in other words, all of the elements in the range [lp,rp) are zero
            if(nums[lp]==0)
            {
                rp = rp==-1?lp+1:rp;                    //rp first time initialization
                while(rp<n && nums[rp]==0)              //keep searching for the first non-zero element after lp
                rp++;
                if(rp==n) return;                       //break if search covers the array since that means no more non-zero elements are present (task done)
                nums[lp] = nums[rp];                    //swap
                nums[rp] = 0;
                rp++;                                   //move rp to next element
            }
            lp++;                                       //move lp to next element
        }
    }

int main(){
}
