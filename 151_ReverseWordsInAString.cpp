#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        s+=" ";
        string temp="",wrd="";
        for(auto i: s)
        {
            if(i!=' ')
            wrd+=i;
            else
            {
                if(wrd.length()==0)
                continue;
                if(temp.length()==0)
                temp=wrd+temp;
                else
                temp=wrd+" "+temp;
                wrd="";
            }
        }
        return (temp);
    }

int main(){
    cout<<reverseWords("a good   example");
}