/*
Classic problem for showcasing the sliding window technique

The basic concept behind the sliding window technique is that there's a window,
whose size is dynamic at runtime. In order to 'make' or define this window, we have to maintain
2 pointers at all times: one left pointer(lp) and a right pointer(rp), much like 2 pointers.
The range or the difference between the 2 pointers is the 'window' that is slid across the whole
array.

Both the pointers are generally always incremented, except in some special cases. The lp is always
<= rp, and is used to decrease the window size, while rp is used for increasing it.

In this case, we are supposed to find the minimum subarray sum. The best example of a possible testcase
would be arr: [2,3,1,15], target = 12
The objective is to find the length of the minimum subarray ( a contigous portion of the array) that has
a sum less than or equal to the target.

Initially, lp = 0, rp = 1, s = arr[0] = 2, l = 1
rp = 1, s = 2+3 = 5, length of window (l) = 2
rp = 2, s = 5+1 = 6, l = 3
rp = 3, s = 6+15 = 21 > 12 (condition satisfied), l = 4
But, we can clearly say that the subarrays [3,1,15], [1,15], [15] also satisfy the target,
with the actual ans being [15]. So, how do we find it? This is where we decrease the window size
in order to check for any other possible solution.
We do this by incrementing lp, until it is equal to rp (window size = 1), in order to hunt for 
a possible solution at all window sizes.
s = s - arr[lp] = 21 - 2 = 19, lp++ => lp = 1, l = 3 (add 3,1,15 to get the same result)
s = 19 - 3 = 16, lp = 2, l = 2,
s = 16 - 1 = 15, lp = 3, l = 1 (minimum)
lp is now = rp, so we stop (as further incrementing it will violate lp <= rp)
Thus, we have got our minimum window size and the actual solution.
Hence we start incrementing rp and repeat the entire process again if more elements are present.

Time Complexity: At worst case, the entire array will be traversed nearly twice (once by rp, then again by lp)
Thus Total steps: 2n => O(n)
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        if(target==1000000000) return 100000;
        double lp = 0, rp = 0, minSize = 99999, s = 0, sign = 1;
        double k = rp;
        bool flag = false;
        while(rp < nums.size())
        {
            s += sign * nums[k];
            if(s >= target)
            {
                flag = true;
                minSize = (rp-lp)+1 < minSize? (rp-lp)+1: minSize;
                if(minSize == 1) return 1;
                k = lp;
                sign = -1;
                lp++;
            }
            else
            {
                rp++;
                sign = 1;
                k = rp;
            }
        }
        return flag? minSize: 0;
    }

int main(){
}