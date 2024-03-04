#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
vector<int> sortedSquares(vector<int>& nums) {
        int count = -1, j;
        for(j=0;j<nums.size();j++){
            if(nums[j]<0)
            count++;
            else
            break;
        }
        vector<int>arr(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            if(count>=0 && j<nums.size()){
                if(nums[count]*nums[count] > nums[j]*nums[j])
                {
                    arr[i] = nums[j]*nums[j];
                    j++;
                }
                else{
                    arr[i] = nums[count]*nums[count];
                    count--;
                }
            }
            else if(count>=0 && j==nums.size()){
                arr[i] = nums[count]*nums[count];
                count--;
            }
            else{
                arr[i] = nums[j]*nums[j];
                j++;
            }
        }
        return arr;
    }


int main(){
}