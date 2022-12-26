#include<bits/stdc++.h>
using namespace std;

/*
NOTES:
Restored from draft
Intuition
Each element in the array can be treated as a 'node' that can reach the final node or position in the array. 
We check for each node if it can reach the final node and mark it accordingly.
Approach
Start scanning from the end of the array. This will make our job of knowing whether the last node is 
reachable from the current node or not much easier.
*/

bool canJump(vector<int>& nums) {
    int flag = nums.size()-1;           //Flag will keep track of the nearest node that can reach the final node
    for(int i=nums.size()-2;i>=0;i--)
    flag = (i+nums[i])>=flag?i:flag;    //Check if the current node can reach the nearest reachable node 
    return flag==0?true:false;      
}


int main(){
    vector<int>test{0,2,3,2,9,1,0};
    cout<<canJump(test);
}