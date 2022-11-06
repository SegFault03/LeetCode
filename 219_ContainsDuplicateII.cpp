#include<bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>table;
        for(int i=0;i<nums.size();i++)
        {
            if(table[nums[i]].size()==0)
                table[nums[i]].push_back(i);
            else
            {
                int diff = i-table[nums[i]][0];
                if(diff<=k)
                    return true;
                else
                    table[nums[i]][0]=i;
            }
        }
        return false;
    }

int main(){
    vector<int>test{1,2,3,1,2,3};
    cout<<containsNearbyDuplicate(test,2);
}