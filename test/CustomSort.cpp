#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>&a, vector<int>&b)
{
    return a[0] < b[0];
}


int main(){
    vector<vector<int>>test{{3,5},{1,2},{5,6},{1,6}};
    sort(test.begin(), test.end(), comparator);
    for(auto i: test)
    cout<<"["<<i[0]<<","<<i[1]<<"]"<<" ";
}