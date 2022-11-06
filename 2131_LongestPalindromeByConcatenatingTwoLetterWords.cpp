#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words) {
      bool mid = false;
      map<string,int>track;
      int l=0;
      for(auto i: words)
      {
          string temp = i;
          reverse(temp.begin(),temp.end());
          if(temp==i)
          {
              if(!mid)
              {
                l+=2;
                mid = true;
              }
          }
          else
          {
              track[i]++;
              if(track[temp]==track[i])
              {
                l+=4;
              }
          }
      }
      return l;
}

int main(){
    vector<string>test{"lc","cl","gg","cl"};
    cout<<longestPalindrome(test);
}