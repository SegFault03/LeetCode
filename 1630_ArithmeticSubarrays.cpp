#include<bits/stdc++.h>
using namespace std;
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
{
    vector<bool>ans;
    for(int i=0;i<l.size();i++)
    {
        int start = l[i], end=r[i];
        auto sp = nums.begin()+start; 
        auto ep = nums.begin()+end+1;
        vector<int>temp{sp,ep};
        sort(temp.begin(),temp.end());
        int diff = temp[1]-temp[0];
        bool flag = true;
        for(int j=2;j<temp.size();j++)
        {
            if(temp[j]-temp[j-1]!=diff)
            {
                flag = false;
                break;
            }
        }
        ans.push_back(flag);
    }
    return ans;    
}


vector<bool> checkArithmeticSubarrays2(vector<int>& nums, vector<int>& l, vector<int>& r) 
{
    vector<bool>ans;
    for(int i=0;i<l.size();i++)
    {
        int start = l[i], end=r[i];
        auto sp = nums.begin()+start; 
        auto ep = nums.begin()+end+1;
        vector<int>temp{sp,ep};
        int min=99999, max=-99999, sum=0;
        for(auto k: temp)
        {
            if(abs(k)<min)
                min=abs(k);
            if(abs(k)>max)
                max=abs(k);
            sum+=abs(k);
        }
        int d = (max-min)/(temp.size()-1);
        int ap_sum = (temp.size()*(2*min+(temp.size()-1)*d))/2;
        if(ap_sum==sum)
        ans.push_back(true);
        else
        ans.push_back(false);
    }
    return ans;
}


int main(){
    vector<int>nums{-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int>l{0,1,6,4,8,7};
    vector<int>r{4,4,9,7,9,10};
    vector<bool>ans=checkArithmeticSubarrays2(nums,l,r);
    for(auto i: ans)
    cout<<i<<" ";
}