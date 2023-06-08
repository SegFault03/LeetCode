/*
Given matrix here is sorted both column and row-wise.
We can take advantage of this fact in order to calculate total number of negative numbers.
Intuition:
-> Start searching from the bottom of the matrix as that is where most negative numbers would be
-> We initally start at the bottom-left corner
-> if it is a positive number, move right (as all the numbers in the current column must be +ve)
-> if negative, add total no. of cols - current col index to total count (as all numbers after it must be -ve)
    and move up. (we've already established that previous cols must have +ve no.s, but we haveno idea if the 
    number at current col - 1 is +ve or -ve.)
-> Keep doing until row >= 0 (can't go up anymore) or col = total cols (can't go right any more)

The idea is to find the 'boundary' from where the -ve numbers start.
Complexity: Worst case = O(m+n) (when the negative numbers are in the lower triangle of the matrix / only present 
in the last columnn )
Best case: O(m) (when matrix has no -ve numbers) 
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
        int num = 0, row = grid.size()-1, col = 0;     //start at grid[col-1][0] 
        while(row>=0 && col<grid[0].size())
        {
            if(grid[row][col]<0)                       //if negative, move up
            {
                num += (grid[0].size()-col);           //since all remaining numbers are negative, add them
                row--;
            }
            else
            col++;                                     //if +ve, move right
        }
        return num;
    }


int main(){
}