#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        // Handle base case: string with only one character
        if (s.length() == 1) return 1;

        // Create a map to store character frequencies
        vector<int> charMap(26, 0);

        int maxLength = -1; // Stores the maximum ideal subsequence length found so far

        for (char ch : s) {
            int idx = ch - 'a'; // Get character index (a=0, b=1, etc.)

            // Define lower and upper bounds based on k (considering alphabet limits)
            int lowerBound = idx - k < 0 ? 0 : idx - k;
            int upperBound = idx + k >= 26 ? 25 : idx + k;

            // Update frequency of current character
            charMap[idx]++;

            // Explore potential previous characters within the allowed range (excluding ch itself)
            for (int i = lowerBound; i <= upperBound; i++) {
                if (i != idx) { // Avoid comparing with itself
                    // Consider the maximum length ending at ch:
                    // 1. Current frequency of ch (single-character subsequence)
                    // 2. Length ending at previous char (charMap[i]) + 1 (adding ch)
                    charMap[idx] = max(charMap[idx], 1 + charMap[i]);
                }
            }

            // Update maxLength with the maximum frequency encountered so far
            maxLength = max(maxLength, charMap[idx]);
        }

        return maxLength;
    }
};
