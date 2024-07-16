#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;

/**
 * ACCEPTED SOLUTION
 */


int main(){
}
class Solution {
public:
    int i = 0;
    string strReverse(string &s){
        stack<string> stack;
        string temp="", temp2="";
        int level=0;
        while (i < s.length()) {
            level = stack.size();
            cout<<s[i];
            if (s[i] == '(') {
                stack.push("");
            } else if (s[i] == ')') {
                temp = stack.top();
                stack.pop();
                if (stack.size() == 0) {
                    break;
                }
                temp2 = stack.top();
                level = stack.size();
                stack.pop();
                if (level % 2 == 0) {
                    stack.push(temp2 + temp);
                } else {
                    stack.push(temp + temp2);
                }
            } else {
                temp = stack.top();
                stack.pop();
                if (level % 2 == 0) {
                    stack.push(temp + s[i]);
                } else {
                    stack.push(s[i] + temp);
                }
            }
            i++;
        }
        return temp;
    }

    string reverseParentheses(string s) {
        stack<string> stack;
        string s2 = "";
        int level;
        while(i<s.length()){
            cout<<s[i]<<endl;
            if(s[i]=='(')
            {
                s2+=strReverse(s);
            }
            else
            {
                s2+=s[i];
            }
            i++;
        }
        return s2;
    }
};