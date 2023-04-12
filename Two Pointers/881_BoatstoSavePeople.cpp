#include<bits/stdc++.h>
using namespace std;

/*
Algorithm: Two Pointers + Greedy.

The problem is simple enough: Maximize weight of each boat as much as possible since only 2 persons can be 
carried. Had the boats been able to carry an infinite number of people, we could've simply sorted the array,
filled as many people we can until it gets overweight, thus minimizing the number of boats required.
But that is not the case here.

Instead we use a 2 pointer approach to find the maximum possible sum(stc) using 2 elements. For that we (obviously)
have to sort the array. The algorithm goes a bit like this:

1. Set right-pointer(rp) to arr.size()-1 and left-pointer(lp) to 0.
2. Check if arr[lp]+arr[rp]<=limit
   i.IF FALSE:
        a. That indicates that the element present at arr[rp] CANNOT be paired up with any other element. That is
           because every other element after arr[lp] is > arr[lp], and if arr[lp]+arr[rp]<=limit, then of course
           it follows that the sum of arr[rp] and any other element after arr[rp] will never be <= limit. Which
           means it must travel alone :( 
        b. Update boatCount++ and rp--.
   ii.ELSE:
        a. This means arr[lp]+arr[rp]<=limit is true, which means the two elements can be paired up.
        b. Update boatCount++ and rp--, lp++.
3. Keep doing until lp<rp.
4. Now, we must make sure that every person (or element) has boarded a boat, either with a partner, or alone.
   Thankfully, we've decremented or incremented our pointers, which mean every element before lp and after rp
   have already boarded the boat. But let us consider what happens when the loop terminates. There can be two 
   possible cases:
   a. lp>rp: This arises IF AND ONLY IF the latest two elements have been paired up (See 2.ii.b). This means all
      elements have boarded.
   b. lp=rp. This means every element except arr[rp] (or arr[lp]) has boarded. (See 2.i.b). Thus update boatCount
      in this case.

Time Complexity: O(nlogn) {For sorting only, two pointers algo takes O(n) time}
Space Complexity: O(n) {again, for sorting only, we make use of constant extra space for implementing two-pointers}
*/

int numRescueBoats(vector<int>& people, int limit) {
        int boatCount = 0, n = people.size();
        int lp = 0, rp = n - 1;
        sort(people.begin(),people.end());
        while(rp>lp)
        {
            if(people[lp]+people[rp]<=limit)
            lp++;
            boatCount++;
            rp--;
        }
        if(lp==rp)
        boatCount++;
        return boatCount;
    }

int main(){
}