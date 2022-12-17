#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<long long int>stack;
    int t=1;
    stack.push(stoi(tokens[0]));
    while(!stack.empty() && t<tokens.size())
    {
        if(tokens[t]!="+"&&tokens[t]!="-"&&tokens[t]!="/"&&tokens[t]!="*")
        stack.push(stoi(tokens[t]));
        else
        {
            long long int b = stack.top();
            stack.pop();
            long long int a = stack.top();
            stack.pop();
            long long int c=0;
            if(tokens[t]=="+")
            c=a+b;
            else if(tokens[t]=="-")
            c=a-b;
            else if(tokens[t]=="*")
            c=a*b;
            else
            c=a/b;
            stack.push(c);
        }
        t++;
    }
    return stack.top();
}

int main(){
    vector<string>tok{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(tok);
}

