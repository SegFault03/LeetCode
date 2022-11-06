#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abcabcbb";
    if(s.length()==0)
    return 0;
    map<char,vector<int>>freq;
    freq[s[0]].push_back(1);
    freq[s[0]].push_back(1);
    int max=1;
    int temp=1;
    for(int i=1;i<s.length();i++)
    {
        if(freq[s[i]].size()==0)
        freq[s[i]].push_back(1);
        else
        freq[s[i]][0]++;
        if(freq[s[i]][0]==1)
        {
            freq[s[i]].push_back(i+1);
            temp++;
        }
        else
        {
            if(temp>max)
            max=temp;
            temp = (temp+1)-freq[s[i]][1];
            freq[s[i]][0]=1;
            freq[s[i]][1]=i+1;
        }
    }
    if(temp>max)
    max=temp;
return max;
}