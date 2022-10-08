#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
        char col = colors[0],temp;
        int time=0,max_time=0;
        for(int i=1;i<neededTime.size();i++)
        {
            temp = colors[i];
            if(col==colors[i])
            {
                time+=(neededTime[max_time]<=neededTime[i]?neededTime[max_time]:neededTime[i]);
                max_time = neededTime[max_time]<=neededTime[i]?i:max_time;
            }
            else
            {
                col=colors[i];
                max_time = i;
            }
        }
        return time;
}

int main()
{
    string colors = "aabaa";
    vector<int>nt={1,2,3,4,1};
    cout<<minCost(colors,nt);
}
