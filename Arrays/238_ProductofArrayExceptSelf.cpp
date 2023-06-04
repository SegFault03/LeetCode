//ACEEPTED SOLUTION
#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int f=1,p=1,n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++)                      //Record cumulative product from left -> right
        {
            p *= nums[i];
            ans[i] = p;
        }
        ans[n-1] = ans[n-2];                        //Calculate for ans[n-1]
        for(int i=n-2;i>0;i--)
        {
            f  *= nums[i+1];                        //Record cumulative product from right -> left
            ans[i] = ans[i-1] * f;                  //Required: cumulative product before i * cumulative product after i
        }
        ans[0] = f * nums[1];                       //Calculate for ans[0]
        return ans; 
    }


int main(){
    vector<int>test{4,3,2,1,5,2};
    vector<int>ans2(productExceptSelf(test));
    for(int i: ans2) cout<<i<<" ";
}