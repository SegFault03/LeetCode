#include<bits/stdc++.h>
using namespace std;
/*
NOTES:
The key concept to identify in this problem is that there exists only ONE possible solution for any given test case.

OPTIMALITY PROOF:
Now let's consider a contradiction to the above statement. Let's say that there exists multiple solutions.
Take 5 gas stations for example:- a -> b -> c -> d -> e. Let's say it is possible to travel from b to b as well as
from c to c in one clockwise rotation. Now, it is important to note that if the point that we're searching for
is present within a path, say a -> b -> ..... -> c -> ..., (where, say the gas station from which if we start, we can
camplete a full rotation is 'b') then it is also possible to travel from a back to a. This is because if it is possible
to travel from b and do a full rotation , then it must also be possible to travel from a and do a full rotation. After
all, b comes after a, and any petrol that we might need to spend (or refill) will be nearly the same. 

We can consider a more practical example: Say we want to go from Ashram to Manamgement House via Gurukul. Then the path 
from Ashram to Mngmt house will also include the path from Gurukul to Mngmt House. Moreover, if it is possible to travel 
from Gkl to Mngmt house, then it obviously follows that it is also possible to travel from Ashram to Mngmt house (provided 
it is possible to travel from Ashram to Gkl). The inverse is also true. If it is not possible to travel from Ashram to Gkl,
or from Gkl to Mngmt, then it is also not possible to travel from Ashram to Mngmt. 

This implies that if some path a -> b -> ..... -> c -> ..., starting from 'a' contains a point say 'c', from which a full 
rotation can be completed, we can prove that we can also complete one full rotation from a. Obviously, it follows that for
the above statement to be true, it must also be possible to travel from a to c in the first place.

Now let's go back to our first scenario, that of the five gas stations a,b,c,d,e. Let's say we start travelling from a. IF at any 
point, we are no longer able to travel further (say our tank is emptied before we reach c, and we can tavel no more), then it
automatically follows that not only is a not the desired point, but b and c is neither. This is because had b or c been the required
points, we should have been able to travel from b or from c back to a. (See above statement for more clarity). So we won't bother
checking if b or c are the required points and go straight to d. One more thing to keep in mind is that if we make a full rotation and
we do not find any point from which we could complete a full rotation, we should give up searching. 
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,curr=0,rem;
        bool vis=false, trip=false;
        rem = gas[start];
        int n = gas.size();
        while(true)
        {
            if(curr==start && vis)                                  //checks if we have reached initial point
            return curr;
            if(rem>=cost[curr])
            {
                vis = true;
                rem-=cost[curr];                                    //Update remaining fuel
                curr++;
                if(curr>=gas.size())                                //A full rotation is complete
                {
                    trip=true;
                    curr = curr%n;                                  //Reset curr to be within the desired limits (0 to gas.size()-1)
                }
                rem+=gas[curr];                                     //Update remaining fuel
            }
            else
            {
                if(trip)
                return -1;                                          //A full rotation is complete and we still haven't found a point -> No such point exists
                else
                {
                    curr++;                                         //Start checking the next point
                    if(curr>=gas.size())
                    {
                        trip=true;
                        curr = curr%n;
                    }
                    start = curr;
                    rem = gas[start];
                    vis = false;
                }
            }
        }
    }

int main(){
    vector<int>t1{2,3,4},t2{3,4,3};
    cout<<canCompleteCircuit(t1,t2);
}