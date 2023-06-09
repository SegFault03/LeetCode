//ACCEPTED SOLUTION
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        int lp = 0, rp = s.length() - 1;
        while(rp > lp)
        {
            if((s[lp]>='A' && s[lp]<='Z') || (s[lp]>='a' && s[lp]<='z') || (s[lp]>=48 && s[lp]<=57))
            {
                if((s[rp]>='A' && s[rp]<='Z') || (s[rp]>='a' && s[rp]<='z') || (s[rp]>=48 && s[rp]<=57))
                {
                    if((s[lp]>=48 && s[lp]<=57) || (s[rp]>=48 && s[rp]<=57))
                    {
                        if(s[lp]==s[rp])
                        {
                            lp++;
                            rp--;
                            continue;
                        }
                        else return false;
                    }
                    else if(s[lp]==s[rp] || abs(s[lp]-s[rp])==32)
                    {
                        lp++;
                        rp--;
                        continue;
                    }
                    else return false;
                }
                else rp--;
            }
            else lp++;
        }
        return true;   
    }

int main(){
    cout<<isPalindrome("0P");
}