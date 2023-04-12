#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    path+='/';
    int i = -1, l = path.length();
    string cp="", dotStore="";
    while(++i<l)
    {
        if(path[i]=='/')
        {
            if(dotStore.length()==0)
            {
                if(cp.length()==0) cp+='/';
                if(cp[cp.length()-1]!='/') cp+='/';
            }
            else
            {
                
                if(dotStore.length()==2 && cp.length()>1)
                {
                    cp.pop_back();
                    while(cp[cp.length()-1]!='/') cp.pop_back();
                }

                if(dotStore.length()>2)
                {
                    for(int j=0;j<dotStore.length();j++) cp.push_back('.');
                    cp.push_back('/');
                }
                dotStore="";
            }
        }
        else if(path[i]=='.' && cp[cp.length()-1]=='/') dotStore.push_back('.');
        else {
            for(int j=0;j<dotStore.length();j++) cp.push_back('.');
            cp.push_back(path[i]);
            dotStore="";
        }
    }
    if(cp[cp.length()-1]=='/' && cp.length()>1) cp.pop_back();
    return cp;
}

int main(){
    cout<<simplifyPath("/..home/..../.././.../alone../a/b//c/./.../..");
}