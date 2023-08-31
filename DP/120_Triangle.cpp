#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        vector<int>curr(triangle[r-1].size(),0);
        curr[0] = triangle[0][0];
        for(int i=0;i<r-1;i++)
        {
            vector<int>nxt(r,INT_MAX);
            for(int j=0;j<triangle[i].size();j++)                           //save the most optimal way to reach the next step
            {
                nxt[j] = min(nxt[j],triangle[i+1][j]+curr[j]);          
                nxt[j+1] = min(nxt[j+1],triangle[i+1][j+1]+curr[j]);
            }
            curr = nxt;
        }
        int minCost = INT_MAX;
        for(int i=0;i<triangle[r-1].size();i++)
        minCost = minCost > curr[i]?curr[i]:minCost;
        return minCost;
    }

int main(){
}