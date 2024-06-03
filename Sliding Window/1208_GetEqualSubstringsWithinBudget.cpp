#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * This function finds the maximum length of a substring in 's' that can be transformed 
 * to the corresponding substring in 't' with a total cost less than or equal to 'maxCost'.
 * The cost of transformation is the absolute difference in ASCII values of the characters being changed.
 *
 * **Approach:**
 * - Uses a sliding window technique with two pointers (`lp` and `rp`).
 * - Iterates through the string 's' using the right pointer (`rp`).
 * - Calculates the cost of changing the character at `rp` in 's' to the corresponding character in 't'.
 * - If the cost is within the remaining allowed cost (`remCost`):
 *      - Deducts the cost from `remCost`.
 *      - Increments `rp` to move the window right.
 *      - Updates `maxL` (maximum valid substring length) if the current window length is larger.
 * - If the cost exceeds the remaining allowed cost:
 *      - If the window isn't empty (`lp < rp`), reverts the change from the left side by adding back the cost.
 *      - Increments `lp` to move the window left (shrinking the window).
 *      - Handles the case where the window becomes empty after shrinking.
 * - Returns the `maxL` (maximum length of the valid substring found).
 */
int equalSubstring(string s, string t, int maxCost) {
  int lp = 0, rp = 0, maxL = 0, remCost = maxCost;
  while (rp < s.length()) {
    if (remCost - abs(s[rp] - t[rp]) >= 0) { // Check if cost within limit
      remCost -= abs(s[rp] - t[rp]);
      rp++;
      maxL = max(maxL, rp - lp);
    } else {
      if (lp < rp) // Revert change from left side if exceeding cost
        remCost += abs(s[lp] - t[lp]);
      lp++;
      if (lp == rp + 1) // Move rp if window becomes empty after shrinking
        rp++;
    }
  }
  return maxL;
}




int main(){
}