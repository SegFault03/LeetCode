#include<bits/stdc++.h>
using namespace std;

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m = spells.size(), n = potions.size();
        int lb = 0, ub = n-1, mid, lastValid = -1;
        vector<int>ans(m,0);
        for(int i = 0;i<m;i++)
        {
            lastValid = -1;
            long long unsigned int tempSuccess = 0;
            lb = 0;
            ub = n-1;
            while(lb<=ub)
            {
                mid = lb+(ub-lb)/2;
                long long spell = spells[i];
                long long potion = potions[mid];
                tempSuccess = spell * potion;
                if(tempSuccess >= success)
                {
                    lastValid = mid;
                    ub = mid - 1;
                }
                else
                lb = mid + 1;
            }
            if(lastValid==-1)
            ans[i] = 0;
            else
            ans[i] = n-lastValid;
        }
        return ans;
    }

int main(){
    vector<int>s{5,1,3},p{1,2,3,4,5};int su=7;
    vector<int>ans(successfulPairs(s,p,su));
    for(auto i: ans) cout<<i;
}