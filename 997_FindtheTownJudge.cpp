#include<bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
      vector<vector<int>>arr(n,vector<int>{0,0});
      for(auto i: trust)
      {
        arr[i[0]-1][0]++;
        arr[i[1]-1][1]++;
      }
      for(int i = 0; i < n; i++)
      {
          if(arr[i][0]==0 && arr[i][1]==n-1)
          return i+1;
      }
      return -1;
}

int main(){
    vector<vector<int>>test{{1,2},{1,3},{2,3},{4,3}};
    cout<<findJudge(4,test);
}