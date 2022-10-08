#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,vector<int>>index;
    vector<int>ret;
    for(int i=0;i<nums.size();i++)
    index[nums[i]].push_back(i);
    sort(nums.begin(),nums.end());
    int j=0,k=nums.size()-1;
    while(j<k)
    {
        int sum = nums[j]+nums[k];
        if(sum<target)
        j++;
        else if(sum>target)
        k--;
        else
        {
            if(nums[j]==nums[k])
            {
                ret.push_back(index[nums[j]][0]);
                ret.push_back(index[nums[j]][1]);
            }
            else
            {
                ret.push_back(index[nums[j]][0]);
                ret.push_back(index[nums[k]][0]);
            }
            break;
        }
    }
    return ret;
}
int main(){
    vector<int>test{3,3};
    vector<int>ret=twoSum(test,6);
    cout<<ret[0]<<" "<<ret[1];
}