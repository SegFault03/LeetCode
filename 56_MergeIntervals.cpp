/*
The main objective here is to find discontinuities in the intervals, and separate them.
When two intervals are continuous, we merge them. However, this is hard to do if the
given intervals are in random order. We might find two consecutive intervals that are cont.
and merge them, then later find a discont. interval, and again find an interval cont. 
with the first two intervals. Thus we have to bring some order first: Sorting.
If the intervals are in some ordered form, we can easily find consecutive intervals
that are continuous and merge them.

Sorting by what tho? Two choices: Either sort using starting point, or using
ending point.

If we sort using ending point, we face a problem. Consider the example:
[[5,8],[2,10],[1,4]]
After sorting on the basis of the ending point, it becomes:
[[1,4],[5,8],[2,10]]

Here, the intervals [1,4] and [2,10] are continuous ([1,10]), but they are not
consecutive. Thus we lose track of the interval to merge [2,10] into when we
reach it.

Instead, lets sort it on the basis of the starting point:
[[1,4],[2,10],[5,8]]
We can now easily merge cont. intervals and separate discont. intervals
This is because since intervals are now sorted on the basis of the starting point,
we can be sure that any successive interval we encounter must have a starting
point that is equal to or greater than the previous interval. In this scenario,
the ending point is not a headache, as we do not need to consider it. (It will only
help us identify whether an interval is cont. or not). 

A pictorial representation that this sorting will give us is a bit like this:

i1  ------
i2  -------
i3   ---
i4   -------
i5      ---------
i6         ---
i7                --------
Ans ------------- --------

As one can easily see, all the cont. and discont. intervals appear in a consecutive order,
so we never lose track of the interval that will be formed on merging. 
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>&a, vector<int>&b)                   //custom sort comparator func.
{
    return a[0] < b[0];                                         //asks the question: Should first element come before second element?
}                                                               //The result of the expression forms the ans.    

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), comparator);   //Sort
        int lb = intervals[0][0], ub = intervals[0][1];         //Initial assignment for the pointers of the merged interval
        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i][0]<=ub)                             //Continous interval     
            ub = intervals[i][1] > ub? intervals[i][1]: ub;     //Update ending point    
            else                                                //Discontinous interval
            {
                ans.push_back(vector<int>{lb,ub});              //Push the newly created merged interval    
                lb = intervals[i][0];                           //Re-assign pointers of the merged interval
                ub = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{lb,ub});                      //Push the last merged interval
        return ans;
    }

int main(){
}