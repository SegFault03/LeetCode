/*
Can be solved using a sliding window technique.
We have a fixed window pane size that we 'slide' across the entire array,
adding the new element that came under the window's right edge, and 
discarding the element that the window's left edge just left.
E.g:
a = [1, 2, 3, 4]
Window size = 2
[1,2,3,4]
 ---
initially, left edge of window(l) = 0, right edge(r) = 1, 
(size = right edge - left edge + 1 = 2), sum(s) = sum of elements 
from a[l] to a[r], inclusive = 3
[1,2,3,4]
   ---
i = 2,  r = i, s = 3 + a[r] = 6 
s = s-a[l-1] = 6 - 1 = 5
[1,2,3,4]
     ---
i = 3,  r = i, s = 5 + a[r] = 9 
s = s-a[l-1] = 9 - 2 = 7
This is how we track the cumulative sum

ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        long long int n = nums.size(), s = 0, d = 2*k+1;            //d is the number of elements
        vector<int>ans(n,-1);
        for(int i=0; i<n; i++)                                      //at any given time, i is the right edge
        {
            if(i+1-d>=0)                                            //check size of window
            {
                int l = i-d+1;                                      //set lower limit (this is the index from where the window starts - left edge)
                int p = l + (i-l)/2;                                //get the middle index, this will also be in the index of ans{} where the average will be set
                s += nums[i];                                       //add the new element
                if(l>0 && l<n)
                s -= nums[l-1];                                     //subtract the element at the index that is one less from the index where the window starts, from the sum          
                ans[p] = s/d;                                       //set the avg at the middle index
            }
            else
            s += nums[i];
        }
        return ans;
    }

int main(){
    vector<int>test{7};
    vector<int>ans{getAverages(test,10)};
    for(int i: ans) cout<<i<<" ";
}