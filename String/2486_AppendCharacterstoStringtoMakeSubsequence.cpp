#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
int appendCharacters(string s, string t) {
        int sp=0, tp=0;
        while(tp<t.length() && sp<s.length()){
            if(s[sp]==t[tp])
            tp++;
            sp++;
        }
        return t.length()-tp;
    }


int main(){
}