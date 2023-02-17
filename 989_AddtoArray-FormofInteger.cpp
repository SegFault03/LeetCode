#include<bits/stdc++.h>
using namespace std;
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int i = 0,curr_carry=0,prev_carry=0, sum = 0, n = num.size();
        i = n - 1;
        while(i>=0 || k>0)
        {
            if(i>=0)
            {
                sum = num[i] + (k%10) + prev_carry;
                i--;
                k /= 10;
                prev_carry = sum / 10; 
                ans.push_back(sum % 10);
                continue;
            }
            if(i<0 && k>0)
            {
                sum = (k%10) + prev_carry;  
                k /= 10;
                prev_carry = sum / 10; 
                ans.push_back(sum % 10);
            }
            
        }
        if(prev_carry>0)
        ans.push_back(prev_carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }

int main(){
    vector<int>test{499};
    for(int i: addToArrayForm(test,1999))
    cout<<i;
}