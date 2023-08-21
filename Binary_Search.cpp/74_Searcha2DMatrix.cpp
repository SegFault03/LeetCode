//2D BINARY SEARCH
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ml = 0, mu = m-1, nl = 0, nu = n-1;
        //COLUMN-WISE BINARY SEARCH
        while(ml<=mu)
        {
            int mid = ml+(mu-ml)/2;
            if(target==matrix[mid][0])
            return true;
            else if(target>matrix[mid][0])
            ml = mid+1;
            else
            mu = mid-1;
        }
        int row = mu<0?ml:mu;
        //ROW-WISE BINARY SEARCH FOR ROW = row
        while(nl<=nu)
        {
            int mid = nl+(nu-nl)/2;
            if(target==matrix[row][mid])
            return true;
            else if(target>matrix[row][mid])
            nl = mid+1;
            else
            nu = mid-1;
        }
        return false;
    }


int main(){
}