#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

/*
ACCEPTED SOLUTION
Approach to solve the problem:
1. Sort the array to facilitate counting elements greater than or equal to a given number using binary search.
2. Use binary search to efficiently find the special number x.
   - Initialize the search range with lb (lower bound) as 0 and ub (upper bound) as the maximum value in the array.
   - For each midpoint (mid) in the binary search, use lower_bound to find the first position where mid could be inserted.
   - Calculate the number of elements greater than or equal to mid.
   - Adjust the bounds based on the comparison of this count with mid.
   - If the count equals mid, return mid as the special number.
   - If no special number is found, return -1.
*/

int specialArray(vector<int>& nums) {
    // Sort the array to allow binary search operations
    sort(nums.begin(), nums.end());

    // Initialize the search bounds
    int ub = nums[nums.size() - 1]; // Upper bound is the maximum value in nums
    int lb = 0; // Lower bound is 0
    int mid; // Variable to store the midpoint during binary search

    // Perform binary search
    while (ub >= lb) {
        // Calculate the midpoint to check
        mid = lb + (ub - lb) / 2;

        // Find the index of the first element >= mid
        int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();

        // If idx is equal to the size of the array, all elements are less than mid
        if (idx == nums.size()) {
            ub = mid - 1;
            continue;
        }

        // Calculate the number of elements >= mid
        int count = nums.size() - idx;

        // If count equals mid, we found the special number
        if (count == mid) {
            return mid;
        }
        // Adjust bounds based on comparison
        else if (count < mid) {
            ub = mid - 1; // Reduce upper bound if count is less than mid
        } else {
            lb = mid + 1; // Increase lower bound if count is greater than mid
        }
    }

    // Return -1 if no special number is found
    return -1;
}


int main(){
    vector<int>t{0,1,2,3,4,5,6};
    cout<<specialArray(t);
}