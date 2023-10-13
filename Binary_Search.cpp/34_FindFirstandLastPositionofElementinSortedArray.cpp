/**
 * Divide & Conquer Strat
 * -> Apply regular binary search techniques to search for target
 * -> Once found, check [mid+1, right] or right portion of the array to find the end position
 * -> Similarly, search for [left, mid-1] or left portion of the array to find the start position
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
void search(
        int left, 
        int right, 
        int *start, 
        int *end,
        int target,
        vector<int>&arr
    ){
        if(left>right)
        return;
        int mid;
        while(left<=right){
            mid = left+((right-left)/2);
            if(arr[mid]==target){
                if(*start==-1 && *end==-1)                  //when target is found for the first time
                {
                    *start = mid;
                    *end = mid;
                    search(
                         mid+1,
                         right,
                         start,
                         end,
                         target,
                         arr
                     );
                     search(
                         left,
                         mid-1,
                         start,
                         end,
                         target,
                         arr
                     );
                }
                if(mid>*end && mid<arr.size()){         
                    *end = mid;     
                     search(
                         mid+1,
                         right,
                         start,
                         end,
                         target,
                         arr
                     );
                }
                if(mid<*start && mid>=0){
                    *start = mid;
                    search(
                         left,
                         mid-1,
                         start,
                         end,
                         target,
                         arr
                     );
                }
                break;
            }
            else if(arr[mid]>target)
            right = mid-1;
            else
            left = mid+1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target) return vector<int>{0,0};
        if(nums.size()==1 && nums[0]!=target) return vector<int>{-1,-1};
        int start = -1, end = -1;
        int left = 0, right = nums.size()-1;
        search(
            left,
            right,
            &start,
            &end,
            target,
            nums
        );
        return vector<int>{start,end};
    }