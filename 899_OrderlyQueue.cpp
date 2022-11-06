#include<bits/stdc++.h>
using namespace std;

string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return(s);
        }
        else
        {
            string min=s;
            int l = s.length();
            int pos=0;
            for(int i=0;i<l;i++)
            {
                string temp = s.substr(1,l-1);
                temp = temp+s[0];
                if(min.compare(temp)>0)
                min=temp;
                s=temp;
            }
            return min;
        }
}

int main(){
    cout<<orderlyQueue("dadmacab",1);
}