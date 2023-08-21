/*
Optimization problem from first glance. Meaning it can be solved by using either greedy or DP.
But which one?
Let's consider Greedy first. Let's pick the strategy of choosing the step having min cost of the next two steps each time we take a step.
Let's test this strategy.

Input: cost = [10,15,20]
At i=-1, we choose 10 as min(10,15), we step on i=0, total cost = 10
i=0, We choose 15, we go to i=1, total cost = 10+15 = 25
i=1, We can directly go to i=3, by taking 2 steps.
Thus, total cost following the greedy strategy of choosing the min of the next two step = 25

However, it can be easily seen that if we step on i=1 first, then take another two steps to i=3,
the total cost = 15. Thus we can see that greedy strategy will not work in this case.
Why? Because when trying to solve problem using greedy strategy, we never care about the future choices (like in this case we do not care about 
the steps that lie beyond the next 2 steps). We only care about the local optimum (in this case we only consider the immediate 2 steps every time 
we make a choice). As a result we might not reach the global optimum. Not to mention once a choice has been made, we never look back, meaning we 
can never consider the case of what might have happened had we made the other choice in the past. Thus we're stuck with the choices we have made.

So is it a DP problem? Let's find out.

The optimal substructure property:
---------------------------------------------------------------------------------------------------------------------------------------------------
IF we want to reach the n'th step, it follows that the (n-1)th or the (n-2)th step, from which we take the next step, must have the min cost
upto that point. Only then can the total cost be minimum. This is a bit like going from point A to point B via C. IF some path A to B is the 
shortest possible path between A and B, and some path B to C is the shortest possible path between B to C, it automatically follows that the path
A to C via B is the shortest possible path between A to C. Thus the global optimum depends upon the local optimums. We need to find the min cost to 
reach n-2 th step and n-1 th step, compare them to find out which ne is smaller, then go to the n-1 th step.

From this we have a recursive eqn.: f(n) = min(cost(n-2)+f(n-2), cost(n-1)+f(n-1))
where cost(n) = cost of the n'th step.
f(n) = total cost upto n'th step.
Note that there are only two ways of reaching the n'th step:
(i) We can either take two steps from n-2'th step
(ii) OR we can take one step from n-1'th step
The above equation therefore compares the only two cases that are possible.
Why are we adding the cost? Because in order to calculate total cost upto n (i.e, f(n)), we must also include the cost of the step from which we
take either one or two step to reach the n'th step, as well as the cost upto that point (f(n-2) or f(n-1))  
Thus we've proved the optimal substructure property.

The overlapping subproblem property:
-----------------------------------------------------------------------------------------------------------------------------------------------------
This can be easily proven by constructing a tree for the above eqn.:
                
                  f(5)
                /     \
             f(4)     f(3)
             /  \   /   \ 
           f(3)  f(2)  f(1)

As we can see, f(4) uses f(2), which is also used by f(3). Thus there is an overlap.

Thus we've proved both the properties necessary for the problem to be solved using DP approach.
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int minCostClimbingStairs(vector<int>& cost) {                                      //tn1 = f(n-1), tn2 = f(n-2)
        long long int i = 1,tn1 = 0, tn2 = 0, tn=0, n = cost.size();                //We start from f(1) as f(0) is 0
        while(i<=n)                                                                 //Bottom-up approach - We solve the smallest subproblems (cost of the lower steps) first
        {
            tn = min(tn2+(i-2<0?0:cost[i-2]), tn1+cost[i-1]);                       //<- Objective function to be minimzed to get the optimal solution
            tn2 = tn1;                                                              //i-2<0?... condition to check underflow since we start from i=1
            tn1 = tn;                                               
            i++;
        }
        return tn;
    }


int main(){
}