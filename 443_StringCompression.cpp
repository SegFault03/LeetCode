#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
        int wp=0,count=1,rp=1;
        char lastChar=chars[0];
        while(rp<chars.size())
        {
            if(lastChar!=chars[rp])
            {
                chars[wp] = lastChar;
                wp++;
                if(count>1)
                {
                    string s = to_string(count);
                    int t = 0;
                    while(t<s.length())
                    {
                        chars[wp] = s[t];
                        t++; wp++;
                    }
                }
                count = 1;
                lastChar = chars[rp];
            }
            else
            count++;
            rp++;
        }
        chars[wp] = lastChar;
                wp++;
                if(count>1)
                {
                    string s = to_string(count);
                    int t = 0;
                    while(t<s.length())
                    {
                        chars[wp] = s[t];
                        t++; wp++;
                    }
                }
        return wp;
    }

int main(){
    vector<char>test{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int n = compress(test);
    for(int i = 0;i<n;i++)
    cout<<test[i];
}