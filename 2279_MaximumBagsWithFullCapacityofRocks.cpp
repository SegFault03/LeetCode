#include<bits/stdc++.h>
using namespace std;

/*
NOTES:
The objective is to maximize the number of bags that are filled.
Intuitively, we can make out that if we prioritize the bags that are the closest
to getting filled up, in other words, the bags which require the least stones to
be filled up, we'll acheive three things:
(i) We would have filled at least some bags
(ii) We would have the maximum possible amount of stones remaining (as the bags which
will be filled first would require the least amount of stones)
(iii) Since we still have stones remaining, we can use these to stones to fill the next 
bag, thus maximizing the number of bags filled and acheiving the objective.

This can be done using a simple greedy strategy where we first sort the array on the
basis of the difference between the max capacity and current capacity, thus getting the
array where the bags will be sorted in increasing order of stones needed to fill them up.
We then count the number of bags filled up to get the final answer.
Time complexity = O(nlogn)
*/

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff(rocks.size(),0);
        for(int i=0;i<rocks.size();i++)
        {
            diff[i]=capacity[i]-rocks[i];               //Create the array storing the number of stones needed to fill up the i'th bag
        }
        sort(diff.begin(),diff.end());                  //Sort it in ascending order, so now the bags requiring the least amount of stones come first.
        int c=0,r=additionalRocks;
        for(int j=0;j<diff.size();j++)
        {
            if(diff[j]>0 && diff[j]<=r) 
            {
                r-=diff[j];                             //Distribute stones 
                diff[j]=0;
            }
            c=diff[j]==0?c+1:c;                         //Check if bag is filled up and increment accordingly
            
        }
        return c;
    }

int main(){
}