#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>test{1,2,3,4,5,6,7};
    auto x = test.begin()+2;
    auto y = test.begin()+5+1;
    vector<int>result{x,y};
    for(auto i: result)
    cout<<i<<" ";
}