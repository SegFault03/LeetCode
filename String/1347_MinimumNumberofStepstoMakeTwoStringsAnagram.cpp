#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
    int minSteps(string s, string t) {
         int c = 0;
        unordered_map<char, int> a,b;
        for(int i=0;i<s.length();i++) {
            a[s[i]]++;
            b[t[i]]++;
        }
        for(auto [k,v]: a) {
            if(b.find(k)==b.end())
            c+=v;
            else if(b[k]<v)
            c+=(v-b[k]);
        }
        return c;
    }



int main(){
    string a= "acrrrm" , b = "bystum";
    cout<<minSteps(a,b);
}