//ACCEPTED SOLUTION
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                int t = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = t;
            }
        }
        //Mirror image
        for(int i = 0; i<n/2; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int t = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }

int main(){
    vector<vector<int>>test{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(test);
}