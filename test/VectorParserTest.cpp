#include<bits/stdc++.h>
#include "../Headers/VectorParser.h"
using namespace std;
int main(){
    // string a = "[[1,2,34,5],[10,2,3]]";
    // string b = "[12,10,3]";
    // vector<vector<int>>x{VectorParser::twoDArrayParser(a)};
    // vector<int>y{VectorParser::oneDArrayParser(b)};
    // cout<<"TWO D: ";
    // for(auto i: x)
    // {
    //     cout<<"[";
    //     for(auto y: i)
    //     cout<<y<<" ";
    //     cout<<"], ";
    // }
    // cout<<endl<<"ONE D: ";
    // for(int i: y) cout<<i<<" ";
    string c = "[3,9,20,null,null,15,7]";
    for(auto i: VectorParser::convertToStringVector(c))
    cout<<i<<" ";
}