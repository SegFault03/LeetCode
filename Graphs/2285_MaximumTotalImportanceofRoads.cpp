#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/*
ACCEPTED SOLUTION
Intuition and Logic:

The problem of maximizing the total importance of roads can be solved using a greedy approach. 
The key insight is that we should assign higher values to cities with more connections (higher degree).

Why this works:
1. Each road's importance is the sum of its connected cities' values.
2. A city with more connections contributes its value to more roads.
3. Therefore, assigning higher values to cities with more connections maximizes the total importance.

Proof of optimality:
Let's say we have two cities A and B, where A has more connections than B.
If we swap their assigned values:
- All roads not connected to A or B remain unchanged.
- Roads connected to A lose value, while roads connected to B gain value.
- Since A has more connections, we lose more value than we gain.
Therefore, assigning a higher value to A is always optimal.

Example:
Consider a graph with 4 cities and the following roads: [[0,1], [0,2], [0,3], [1,2]]
Degrees: City 0: 3, City 1: 2, City 2: 2, City 3: 1

Optimal assignment: City 0: 4, City 1: 3, City 2: 2, City 3: 1
Total importance: (4+3) + (4+2) + (4+1) + (3+2) = 7 + 6 + 5 + 5 = 23

If we swap values of cities 0 and 1:
New assignment: City 0: 3, City 1: 4, City 2: 2, City 3: 1
Total importance: (3+4) + (3+2) + (3+1) + (4+2) = 7 + 5 + 4 + 6 = 22

We can see that this swap reduces the total importance, proving that the original assignment was optimal.

Why equal degree doesn't matter:
If two cities have the same degree, swapping their values doesn't change the total importance.

Example:
Consider cities 1 and 2 in the previous example, both with degree 2.
Swapping their values:
Before: City 1: 3, City 2: 2
After:  City 1: 2, City 2: 3

The total importance remains the same because:
- The road (0,1) loses 1, but (0,2) gains 1
- The road (1,2) remains unchanged (3+2 = 2+3)

This property allows us to assign values to equal-degree cities in any order without affecting optimality.
*/

class Solution {
public:
    // Comparator function to sort cities by degree in descending order
    static bool sortByDegree(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Vector to store each city's index and degree
        vector<pair<int,int>> cityDegrees(n, {0, 0});

        // Count the degree of each city
        for (const auto& road : roads) {
            cityDegrees[road[0]].first = road[0];
            cityDegrees[road[0]].second++;
            cityDegrees[road[1]].first = road[1];
            cityDegrees[road[1]].second++;
        }

        // Sort cities by degree in descending order
        sort(cityDegrees.begin(), cityDegrees.end(), sortByDegree);

        long long totalImportance = 0;
        int currentValue = n;

        // Assign values and calculate total importance
        for (const auto& city : cityDegrees) {
            // Multiply city's degree by its assigned value and add to total
            totalImportance += static_cast<long long>(city.second) * currentValue;
            currentValue--;
        }

        return totalImportance;
    }
};


int main(){
}