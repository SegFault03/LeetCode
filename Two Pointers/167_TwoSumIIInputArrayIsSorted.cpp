/*
Simplest example showing how to use the 2-pointers approach.
Here we have to search for two numbers whose sum will be equal to target.
First, in order to implment the 2-pointer approach, it is essential that the
the given data is ordered or sorted in some manner, as otherwise we will be searching blindly.
The 2 pointer approach involves manipulating the two pointers to point at some specific
elements in an array, which can be compared, or operated on in order to achieve a desired
solution, as in this problem. However, there must be some kind of pattern in the data, based on
which the 2 pointers will be manipulated, and therefore the data must be sorted or ordered in some manner.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        int lp = 0, rp = numbers.size()-1, lin,rin; //initially, one pointer points at the largest element, the other at smallest
        while(rp > lp)                              //loop continues as long as the right pointer is right of the left pointer
        {
            //Note: The right pointer will ALWAYS move left, while left pointer will ALWAYS move right.
            //This is how we can cover the entire array.
            if(numbers[rp] + numbers[lp] == target) //if target is fulfilled, break as there is only 1 solution
            {
                lin = lp; 
                rin = rp; 
                break;
            }
            /*
            Target is greater than the sum, meaning we need a bigger number. 
            We can't go right of rp (as we've already explored that), so we go right of lp instead as this will guarantee a bigger number
            */
            else if(numbers[rp] + numbers[lp] < target) lp++;      
            /*
            Target is smaller than the sum, meaning we need a smaller number. 
            We can't go left of lp (as we've already explored that), so we go left of rp instead as this will guarantee a smaller number
            */ 
            else rp--;
        }
        return vector<int>{lin+1, rin+1};
    }

int main(){
}