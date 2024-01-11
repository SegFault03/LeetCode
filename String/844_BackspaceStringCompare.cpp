#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
void transform(string &s){
        int p = -1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(p<0) continue;
                s[p] = '#';
                p--;
            }
            else{
                p++;
                s[p] = s[i];
                if(i>p)
                s[i] = '#';
            }
        }
    }

    int getValidLength(string &s){
        int l = 0;
        for(char ch: s){
            if(ch=='#')
            return l;
            else
            l++;
        }
        return l;
    }

    bool backspaceCompare(string s, string t) {
        transform(s);
        transform(t);
        int a = getValidLength(s), b = getValidLength(t), i=0, j=0;
        if(a!=b) return false;
        for(i=0;i<a;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }


int main(){
    string a = "a##c";
    string b = "#a#c";
    cout<<backspaceCompare(a,b);
}