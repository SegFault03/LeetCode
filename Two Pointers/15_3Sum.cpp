/*
A modified version of 2 sum, follows mostly the same logic.
The only difference is here we fix one of the elements, and find the remaining
2 using 2 pointers, just like in 2 sum.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int lp, rp;
        for(int i = 0; i < nums.size()-2; i++)                              //nums.size()-2 because you need at least 3 distinct elements
        {
            if(i>0 && nums[i]==nums[i-1]) continue;                         //Elements that are same will produce the same results and can therefore be skipped
            int sum = 0;
            lp = i+1;                                                       //lp points to element immediately after i
            rp = nums.size()-1;                                             //rp points to end of array, just like 2 sum    
            while(rp > lp)                                                  //the following while block uses the same logic as 2 sum
            {
                sum = nums[i] + nums[lp] + nums[rp];
                if(sum == 0) 
                {
                    ans.push_back(vector<int>{nums[i],nums[lp],nums[rp]});
                    int k = lp;
                    lp++;                                                   //Check if other possible combinations exist or not
                    while(nums[lp]==nums[k] && lp < rp) {k = lp; lp++;}
                }
                else if(sum > 0) 
                {
                    int k = rp;
                    rp--;                                                   //We need smaller numbers
                    while(nums[rp]==nums[k] && lp < rp) {k = rp; rp--;}
                }
                else 
                {
                    int k = lp;
                    lp++;                                                   //We need bigger numbers
                    while(nums[lp]==nums[k] && lp < rp) {k = lp; lp++;}
                }                                                           //Note that once one nums[i] has been considered, it will never be considered again because 
                                                                            //we have already considered all possible solutions it could have, so no need to consider
            }                                                               //it again. Thus we only move forward.
        }
        return ans;
    }

int main(){
    vector<int>test{-1,0,1,2,-1,-4};
    vector<vector<int>>ans{threeSum(test)};
    for(auto i: ans)
    cout<<"["<<i[0]<<","<<i[1]<<","<<i[2]<<"]"<<endl;
}