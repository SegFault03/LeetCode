/*
Optimization problem to be solved using DP.

Let's say we choose to rob every house. In order to get the total loot upto that point, for the n'th house,
we have to consider two choices:
(i) The loot of n-2'th house
(ii) The loot of the n-3'th house
Why?
We cannot loot adjacent houses. MEaning we cannot consider the loot of n-1'th house if we choose to loot the n'th house.
Thus we consider the loot of n-2'th house. Again, since we are considering the loot of the n2'th house, that means we're
not considering the loot upto n-3'th house, as if we chose to loot n-2'th house, we must have not chosen to rob n-3'th house.
Thus we must consider the loot of n-3'th house separately.
But why are we not considering n-4, n-5, n-6... as well?
This is because the when we considered n-2'th house, we've automatically considered the n-4'th and n-5'th houses (as that must've been
considered when calculating the total loot upto n-2'th house), thus we've no need to consider them again.
Similarly, n-5'th and n-6'th houses would be considered when we consider the n-3'th house, as they must have been considered when
calculating the total loot upto n-3'th house.

Thus we have a recursive eqn. of the form f(n) = loot[n]+max(f(n-2),f(n-3))

Clearly, we can see the optimal substructure property being exhibited (The optimal solution to f(n) depends upon the optimal solutions 
to f(n-2) and f(n-3))

Constructing the tree for the recurisve eqn. would also help us prove the overlapping subproblem property.
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int tn3=nums[0], tn2=nums[1], tn1=nums[0]+nums[2], tn = 0, maxLoot, i=3;    //We only need the n-2'th, n-1'th and n-3'th terms  
        maxLoot = max(tn1, max(tn2, tn3));                                      
        while(i<nums.size())                                                        //bottom-up approach
        {   
            tn = nums[i] + max(tn3, tn2);
            maxLoot = tn>maxLoot?tn:maxLoot;
            tn3 = tn2;                              
            tn2 = tn1;
            tn1 = tn;
            i++;
        }
        return maxLoot;
    }


int main(){
}