#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

/**
 * ACCEPTED SOLUTION
 * The trick is to essentially sort the array, and then fill each array-blocks
 * one by one, while checking if each element is less than the preceding element
 * by <= k. This is because sorting the array will rearrange it into a state
 * where each consecutive elements have the minimum difference, and so if in that
 * case it still doesn't satisfy the <= k condition, no other element can be subs-
 * -tituted in its place. Any upcoming element will always be at-least be equal 
 * or greater and thus have a difference of >k. Similarly, elements which have 
 * already been alloted (that came before the current one) will also suffer from
 * the same problem.
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        if (n % 3 != 0)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(n / 3, vector<int>(3, 0));
        ans[i][j] = nums[0];
        j++;
        for (int m = 1; m < nums.size(); m++) {
            if (j >= 1 && abs(nums[m] - ans[i][j - 1]) > k)
                return vector<vector<int>>();
            ans[i][j] = nums[m];
            j++;
            if (j == 3) {
                if (abs(ans[i][0] - ans[i][2]) > k)
                    return vector<vector<int>>();
                j = 0;
                i++;
            }
        }
        return ans;
    }
};


int main(){
    vector<int>t = {1,3,3,2,7,3};
    (new Solution())->divideArray(t, 3);
}