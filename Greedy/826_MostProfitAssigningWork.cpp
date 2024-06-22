#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/

/*
    The goal of this algorithm is to maximize the total profit from assigning jobs to workers
    based on their abilities. Each worker can only complete a job if their ability is at least 
    as high as the job's difficulty. The same job can be assigned to multiple workers.

    Steps:
    1. **Combining Jobs:** We start by combining the `difficulty` and `profit` arrays into a 
       single vector of pairs where each pair represents a job with its difficulty and profit.
    2. **Sorting Jobs:** We sort this vector of jobs based on their difficulty. This sorting 
       helps in efficiently finding the best job a worker can perform using binary search.
    3. **Updating Profits:** To ensure that each worker can find the best possible job, we 
       update the profits in the sorted job list such that each entry contains the maximum 
       profit obtainable for that difficulty level or any difficulty less than that. This 
       step ensures that we do not miss out on better profits for easier jobs.
    4. **Binary Search for Workers:** For each worker, we perform a binary search on the sorted 
       job list to find the most profitable job they can complete. By comparing the worker's 
       ability to the job's difficulty and adjusting the search bounds, we efficiently find 
       the best job for each worker.
    5. **Total Profit Calculation:** We accumulate the total profit by summing the best possible 
       profit each worker can achieve.

    This algorithm efficiently assigns jobs to workers to maximize the total profit by leveraging 
    sorting and binary search, resulting in a time complexity of O(n log n + m log n).
*/


// Comparator function to sort jobs based on difficulty
bool sortFn(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

/*
    This function assigns jobs to workers to maximize total profit. 

    Algorithm:
    1. Combine job difficulties and profits into a single vector of pairs.
    2. Sort this vector based on job difficulty.
    3. Update the profit values in the sorted job list to ensure that each entry 
       contains the maximum profit obtainable for that difficulty level or less.
    4. For each worker, use binary search to find the best job they can perform
       (i.e., the most profitable job with a difficulty they can handle).
    5. Accumulate the total profit by summing the best possible profit for each worker.
*/

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    // Combine difficulties and profits into a single vector of pairs
    vector<pair<int, int>> jobs(difficulty.size(), {0, 0});
    for (int i = 0; i < difficulty.size(); i++) {
        jobs[i] = {difficulty[i], profit[i]};
    }

    // Sort jobs by difficulty
    sort(jobs.begin(), jobs.end(), sortFn);

    // Update job profits to be the maximum profit for any job of that difficulty or less
    int maxProfit = jobs[0].second;
    for (int i = 1; i < difficulty.size(); i++) {
        maxProfit = max(maxProfit, jobs[i].second);
        jobs[i].second = maxProfit;
    }

    // Initialize total profit
    int totalProfit = 0;
    
    // For each worker, find the most profitable job they can complete using binary search
    for (int ability : worker) {
        int lb = 0, ub = jobs.size() - 1, mid;
        maxProfit = 0;
        
        // Binary search to find the best job for the current worker's ability
        while (lb <= ub) {
            mid = (ub - lb) / 2 + lb;
            if (jobs[mid].first <= ability) {
                maxProfit = max(maxProfit, jobs[mid].second);
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        
        // Add the best job's profit to the total profit
        totalProfit += maxProfit;
    }

    // Return the total profit
    return totalProfit;
}


int main(){
    vector<int>a{68,35,52,47,86},b{67,17,1,81,3},c{92,10,85,84,82};
    cout<<maxProfitAssignment(a, b, c);
}