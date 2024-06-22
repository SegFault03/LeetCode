#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLUTION
Logic and Intuition:

This solution uses a two-pointer approach to efficiently count the number of "nice" subarrays.

Key ideas:
1. Two Pointers:
   - right_pointer: Expands the current subarray to the right.
   - left_pointer: Contracts the subarray from the left when needed.

2. Sliding Window:
   We maintain a window that contains exactly 'k' odd numbers. When we find such a window,
   we count how many subarrays we can form starting from the left_pointer and ending at right_pointer.

3. Counting Nice Subarrays[*]:
   - When we find a window with 'k' odd numbers, we count how many ways we can start this subarray
     (by moving left_pointer) while still keeping 'k' odd numbers.
   - For each even number we encounter after finding a nice subarray, we can form the same number
     of nice subarrays (by extending the previous nice subarrays).

4. Efficiency:
   This approach allows us to count all nice subarrays in a single pass through the array,
   giving us a time complexity of O(n) where n is the length of the input array.

[*]
# Detailed Explanation of Nice Subarray Counting

## 3. Counting Nice Subarrays

### When exactly k odd numbers are found:

When we find a window with exactly k odd numbers, we count how many ways we can start this subarray while still keeping k odd numbers. 
This is done by moving the left pointer to the right until we would remove an odd number.

#### Example:
Let's say k = 3, and we have the following array: [2, 1, 2, 1, 2, 1, 2]
                                                   ^           ^
                                             left_pointer  right_pointer

When right_pointer reaches the third 1, we have found a window with exactly 3 odd numbers. Now we count how many ways we can start this subarray:

1. [2, 1, 2, 1, 2, 1]
2. [1, 2, 1, 2, 1]
3. [2, 1, 2, 1]
4. [1, 2, 1]

In this case, `nice_subarrays_ending_here` would be 4.

### When an even number is encountered after finding a nice subarray:

For each even number we encounter after finding a nice subarray, we can form the same number of nice subarrays as before, 
because adding an even number to the end of a nice subarray doesn't change its "niceness".

#### Example (continuing from above):
If the next number in our array is even, say 2, making the array [2, 1, 2, 1, 2, 1, 2, 2]
                                                                  ^              ^
                                                            left_pointer  right_pointer

We can form 4 new nice subarrays by adding this 2 to each of our previous nice subarrays:

1. [2, 1, 2, 1, 2, 1, 2]
2. [1, 2, 1, 2, 1, 2]
3. [2, 1, 2, 1, 2]
4. [1, 2, 1, 2]

So we add another 4 to our total count of nice subarrays.

### Why `nice_subarrays_ending_here` is reset when `odd_count = k`:

We reset `nice_subarrays_ending_here` every time `odd_count = k` because we're starting a new count for a new set of nice subarrays. 

The reason for this is that when we find a new odd number that makes `odd_count = k`, we've potentially shifted our window of nice subarrays. 
The previous `nice_subarrays_ending_here` count was specific to the previous window position, and it's not necessarily applicable to our new window.

#### Example:
Consider the array [1, 2, 1, 2, 1, 2, 1] with k = 3

1. When we reach the third 1:
   [1, 2, 1, 2, 1]
   We count 3 nice subarrays ending here.

2. When we reach the fourth 1:
   [1, 2, 1, 2, 1, 2, 1]
   We need to start a new count because our window has shifted. The nice subarrays ending here are different from those ending at the previous 
   position.

By resetting and recounting, we ensure that we're always counting the correct number of nice subarrays for the current window position.

This approach allows us to correctly handle all cases, including overlapping nice subarrays and nice subarrays that extend when we add even numbers to the end.
The key intuition is that once we find a nice subarray, we can efficiently count all nice subarrays
ending at the current position without having to recount from the beginning each time.
*/

int numberOfSubarrays(vector<int>& nums, int k) {
    int left_pointer = 0;                 // Left boundary of current window
    int right_pointer = 0;                // Right boundary of current window
    int odd_count = 0;                    // Count of odd numbers in current window
    int nice_subarrays_ending_here = 0;   // Count of nice subarrays ending at right_pointer
    int total_nice_subarrays = 0;         // Total count of nice subarrays

    while (right_pointer < nums.size()) {
        // If current number is odd, update odd_count
        if (nums[right_pointer] % 2 != 0) {
            odd_count++;
            
            // If we have exactly k odd numbers, count nice subarrays
            if (odd_count == k) {
                nice_subarrays_ending_here = 0;
                int temp_left = left_pointer;
                
                // Count all possible starts of nice subarrays ending at right_pointer
                while (temp_left <= right_pointer && odd_count == k) {
                    nice_subarrays_ending_here++;
                    // Move temp_left, reduce odd_count if an odd number is removed
                    odd_count -= nums[temp_left] % 2 != 0 ? 1 : 0;
                    temp_left++;
                }
                
                // Update total count and reset left_pointer and odd_count
                total_nice_subarrays += nice_subarrays_ending_here;
                left_pointer = temp_left;
                odd_count = k;
            }
        } else {
            // If current number is even, we can form the same number of nice subarrays
            // as we did ending at the previous position
            total_nice_subarrays += nice_subarrays_ending_here;
        }
        
        right_pointer++;
    }
    
    return total_nice_subarrays;
}


int main(){
    vector<int>t{1,2,2,1,1,2,2,1,2,2};
    cout<<numberOfSubarrays(t, 3);
}