#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>freq,ind;
        for(int i=0;i<matches.size();i++)
        {
            freq[matches[i][0]]++; freq[matches[i][1]]++;
            ind[matches[i][0]]++; ind[matches[i][1]]++; ind[matches[i][1]]--; 
        }
        vector<vector<int>>ans(2);
        for(auto it: ind)
        {
            int mp = freq[it.first];
            int won = it.second;
            int diff = mp - won;
            if(diff==0)
            ans[0].push_back(it.first);
            if(diff==1)
            ans[1].push_back(it.first);
        }
        return ans;
    }

int main(){
    vector<vector<int>>test{{2,3},{1,3},{5,4},{6,4}};
    vector<vector<int>>ans{findWinners(test)};
    for(auto it: ans)
    {
        for(auto it2: it)
        cout<<it2<<" ";
        cout<<endl;
    }
}