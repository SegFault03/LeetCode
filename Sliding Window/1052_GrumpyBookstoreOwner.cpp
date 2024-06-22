#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLUTION
Logic and Intuition:

This solution uses a sliding window approach to solve the bookstore owner's problem efficiently.

1. First Pass:
   - We calculate the total number of satisfied customers without using the secret technique.
   - We initialize the first window of size 'minutes'.

2. Sliding Window:
   - We slide a window of size 'minutes' across the day.
   - For each window, we calculate:
     a) The total customers in the window (potential satisfaction if technique is used here)
     b) Customers satisfied before the window without the technique
     c) Customers satisfied until the window without the technique (including the window itself)
   - The sum of these gives us the total satisfaction if we use the technique on this window.

3. Optimization:
   - We keep track of the maximum satisfaction found across all windows.
   - This approach ensures we find the optimal place to use the secret technique.

4. Efficiency:
   - By using a sliding window, we avoid recalculating sums for each possible application of the technique.
   - This results in a linear time complexity O(n), where n is the number of minutes.

The key intuition is that the best use of the technique will be on a continuous window of 'minutes' length,
and by sliding this window across the entire day, we can find the optimal placement.
*/

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int satisfiedBeforeWindow = 0;  // Satisfied customers before current window
    int satisfiedInWindow = 0;      // Satisfied customers in current window without technique
    int totalSatisfiedWithoutTechnique = 0;  // Total satisfied customers without using technique
    int currentWindowSum = 0;       // Sum of all customers in current window
    int maxSatisfaction = 0;        // Maximum satisfaction found so far

    // First pass: Calculate total satisfied without technique and initialize first window
    for(int i = 0; i < customers.size(); i++) {
        // Count total satisfied customers without using the technique
        totalSatisfiedWithoutTechnique += (grumpy[i] == 0) ? customers[i] : 0;

        if(i < minutes) {
            // Initialize the first window
            currentWindowSum += customers[i];
            satisfiedInWindow += (grumpy[i] == 0) ? customers[i] : 0;
        }
    }

    // Calculate satisfaction if technique is used on first window
    maxSatisfaction = max(maxSatisfaction, currentWindowSum + totalSatisfiedWithoutTechnique - satisfiedInWindow);

    // Slide the window and find maximum satisfaction
    for(int i = minutes; i < customers.size(); i++) {
        // Update satisfied customers before the window
        satisfiedBeforeWindow += (grumpy[i - minutes] == 0) ? customers[i - minutes] : 0;

        // Slide the window: add new customer, remove first customer of previous window
        currentWindowSum += customers[i] - customers[i - minutes];

        // Update satisfied customers in the new window
        satisfiedInWindow += (grumpy[i] == 0) ? customers[i] : 0;

        // Calculate total satisfaction if technique is used on current window
        int currentSatisfaction = currentWindowSum + satisfiedBeforeWindow + 
                                  totalSatisfiedWithoutTechnique - satisfiedInWindow;

        // Update maximum satisfaction found
        maxSatisfaction = max(currentSatisfaction, maxSatisfaction);
    }

    return maxSatisfaction;
}


int main(){
}