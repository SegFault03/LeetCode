#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int>days(n,0);
    stack<int>stack;
    stack.push(0);
    for(int i=1;i<n;i++)
    {
        if(temperatures[stack.top()]<temperatures[i])
        {
            while(!stack.empty() && temperatures[stack.top()]<temperatures[i])
            {
                days[stack.top()] = i - stack.top();
                stack.pop();
            }
        }
        stack.push(i);
    }
   return days;
}


int main(){
    vector<int>temp{73,74,75,71,69,72,76,73};
    vector<int>out(dailyTemperatures(temp));
    for(int i: out)
    cout<<i<<" ";    
}


