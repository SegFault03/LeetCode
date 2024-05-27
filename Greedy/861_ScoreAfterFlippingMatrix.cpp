#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
int matrixScore(vector<vector<int>>& grid) {
    // Get the number of rows and columns in the grid
    int m = grid.size(), n = grid[0].size();
    bool isFlipped;

    // Iterate over each row
    for (int i = 0; i < m; i++) {
        isFlipped = false;
        // If the first element of the row is 0, flip the row
        if (grid[i][0] == 0) {
            isFlipped = true;
        }
        // Iterate over each column
        for (int j = 1; j < n; j++) {
            // If the row is flipped, toggle the element
            // If not, keep the element as it is
            grid[i][j] = isFlipped?(grid[i][j]==0?1:0):grid[i][j];
            // Add the element to the first row
            if(i>0)
            grid[0][j] += grid[i][j];
        }
    }

    int sum = 0, idx, ones, add;
    // Iterate over each column from right to left
    for (int j = n - 1; j >= 1; j--) {
        idx = n - j - 1;
        // Get the maximum number of 1s in the column
        ones = max(grid[0][j], m - grid[0][j]);
        // Calculate the value to be added to the sum
        add = (int)pow(2, idx);
        // Add the product of the number of 1s and the value to the sum
        sum += ones * add;
    }
    // Add the product of the number of rows and the value of the most significant bit to the sum
    sum += m * (int)(pow(2,n-1));
    // Return the sum
    return sum;
}



int main(){
}