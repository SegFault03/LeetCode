#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
string add_one(string &s){
        bool carry = s[s.length()-1]=='0'?false:true;
        s[s.length()-1] = s[s.length()-1]=='0'?'1':'0';
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]=='1')
            {
                s[i] = carry?'0':'1';
                carry = carry?true:false;
            }
            else
            {
                s[i] = carry?'1':'0';
                carry = false;
            }
        }
        s = carry?"1"+s:s;
        return s;
    }
    int numSteps(string s) {
        int steps = 0;
        while(s.length()>1){
            cout<<"Initial: "<<s;
            if(s[s.length()-1]=='0')
            s.pop_back();
            else
            s = add_one(s);
            steps++;
            cout<<" Final: "<<s<<endl;
        }
        return steps;
    }


int main(){
}