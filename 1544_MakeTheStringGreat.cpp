#include<bits/stdc++.h>
using namespace std;

string makeGood(string s) {
    int i=0,l = s.length();
    stack<char>track;
    track.push(s[0]);
    for(int i=1;i<l;i++)
    {
        char temp = s[i];
        if(track.size()==0)
        {
            track.push(temp);
            continue;
        }
        if(abs(track.top()-temp)==32)
        track.pop();
        else
        track.push(temp);
    }
    string ans="";
    while(track.size()!=0)
    {
        ans = track.top()+ans;
        track.pop();
    }
    return ans;
}
int main(){
    cout<<makeGood("leEeetcode");
}