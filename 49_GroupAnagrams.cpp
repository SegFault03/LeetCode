#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    map<string,vector<int>>dict;
    int i,j;
    for(i=0;i<strs.size();i++)
    {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        dict[temp].push_back(i);
    }
    vector<vector<string>>ans;
    for(map<string,vector<int>>::iterator itr = dict.begin();itr!=dict.end();itr++)
    {
        vector<string>temp;
        for(auto i: itr->second)
        temp.push_back(strs[i]);
        ans.push_back(temp);
    }
    return ans;    
}

int main(){
    vector<string>test{"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    vector<vector<string>>out;
    out = groupAnagrams(test);
    for(int i=0;i<out.size();i++)
    {
        for(int j=0;j<out[i].size();j++)
        cout<<out[i][j]<<" ";
        cout<<endl;
    }
}