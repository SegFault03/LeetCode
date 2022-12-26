#include<bits/stdc++.h>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
{
    sort(nums.begin(),nums.end());
    int n=queries.size();
    vector<int>ans(n,0);
    for(int i=0;i<queries.size();i++)
    {
        int s=0;
        int c=0;
        for(int j: nums)
        {
            if(s+j<queries[i])
            {
                s+=j;
                c++;
            }
            else if(s+j==queries [i])
            {
                c++;
                break;
            }
            else
            break;
        }
        ans[i]=c;
    }
    return(ans);
}

int main(){
}