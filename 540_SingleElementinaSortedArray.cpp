#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid=0;
        if(nums.size()==1)
        return nums[0];
        while(high>=low)
        {
            mid = (high+low)/2;
            if(mid==0)
            {
                if(nums[mid]!=nums[mid+1])
                return nums[mid];
                else 
                low = mid + 1;
            }
            else if(mid==nums.size()-1)
            {
                if(nums[mid]!=nums[mid-1])
                return nums[mid];
                else 
                high = mid - 1;
            }
            else if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
            return nums[mid];
            else if(mid%2==0)
            {
                if(nums[mid+1]==nums[mid])
                low = mid + 1;
                else
                high = mid - 1;
            }
            else
            {
                if(nums[mid+1]==nums[mid])
                high = mid - 1;
                else
                low = mid + 1;
            }
        }
        return 0;
    }
    
int main(){
}