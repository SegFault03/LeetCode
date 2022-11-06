#include<bits/stdc++.h>
using namespace std;
int maxLength(vector<string>& arr) 
{
    if(arr.size()==1)
    return arr[0].size();
    int max = -99999,i,j,k;
    for(i=0;i<arr.size();i++)
    {
        map<char,int>dict;
        string temp_s="";
        int len=0;
        for(j=i;j<arr.size();j++)
        {
            map<char,int>temp=dict;
            bool flag = true;
            for(k=0;k<arr[j].size();k++)
            {
                temp[arr[j][k]]++;
                if(temp[arr[j][k]]>1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                temp_s+=arr[j];
                dict = temp;
                // for(k=0;k<arr[j].size();k++)
                // dict[arr[j].at(k)]++;
            }
        }
        len = temp_s.length();
        if(len>max)
        max=len;
    }
    return max;
}


int main(){
    vector<string>test{"aa","bb"};
    cout<<maxLength(test);
}