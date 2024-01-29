#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLN.
 * The idea is to store a sorted version of all the elements in the current window.
 * A deque can be used to do that (or a priority queue). Every element in the dq
 * is smaller than its predecessor. We also remove elements from the dq as we scan each element,
 * to discard elements that are no longer in the window. This way in each window,
 * the first element of the dq will always have the max element.
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        //Fill the first window
        for(int i=0;i<k;i++) {

            //Pop elements in the dq until the current element is smaller (or equal) to the
            //first element at the back of the dq. This will help us store only the biggest
            //elements in the current window. Also note how we're storing the indexes, and not
            //the element themselves. This is because we might later need to check if a given
            //index belongs in the current window or not.
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k;i<nums.size();i++)
        {
            //The first element will always be the biggest element in the current window.
            ans.push_back(nums[dq.front()]);
            //Check if the index of the first element belongs in the current window or not
            if(!dq.empty() && dq.front()<i-k+1)
            dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();
            dq.push_back(i);
        }
        //Push the max element of the last window
        if(!dq.empty())
        ans.push_back(nums[dq.front()]);
        return ans;
    }

int main(){
    vector<int>t = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    maxSlidingWindow(t, k);
}