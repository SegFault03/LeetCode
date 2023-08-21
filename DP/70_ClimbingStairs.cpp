/*
DP problem to calculate all possible ways to reach the n-th stair.
Why DP?
To reach nth stair, we must calculate the number of steps to reach (n-2)th stair and (n-1)th stair.
Why? Beccause there are two ways we can reach n-th stair:
(i) We either take two steps from n-2 th stair (1 possible way)
(ii) We take a single step from n-1 th stair   (1 possible way)
Thus we need to MEMORIZE the number of possible steps to reach n-1 and n-2 th steps
Also it features overlapping sub-problems:

                 f(5)
               /      \
             f(4)      f(3)
             /  \     /   \ 
           f(2) f(3) f(2) f(1)

As we can see, f(4) uses f(2), which is also used by f(3). Thus there is a overlap.
The final recursive eqn. is of the form: f(n) = f(n-2) + f(n-1)
Let's see another example to make it more clear:
f(1) = {1}
f(2) = {{1,1},{2}}
f(3) = f(2) + f(1)
For f(1),
{{1}, 2} where {1} -> f(1)              [Note: Remember we ALWAYS take 2 steps to reach n from n-2]
For f(2),
{{1,1}, 1}                              [Note: Remember we ALWAYS take 1 step to reach n from n-1]
{{2}, 1}
Thus in total 3 possible ways.
Similarly, for n=4
-------------------------
f(4) = f(3) + f(2)
f(2):
---------
{{1,1},2}
{{2},2}
----------
f(3):
----------
{{1,1,1},1}
{{2,1},1}
{{1,2},1}
Thus total = 5. Hence, f(4) = f(3) + f(2) = 3+2 = 5
*/   
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION

int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        long long int tn_2 = 1, tn_1 = 2, tn = 0, i=3;
        while(i<=n)
        {
            tn = tn_2 + tn_1;
            tn_2 = tn_1;
            tn_1 = tn;
            i++;
        }
        return tn;
    }


int main(){
    cout<<climbStairs(45);
}