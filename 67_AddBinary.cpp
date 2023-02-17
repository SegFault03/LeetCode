#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        int k = a.length()-1, l = b.length()-1;
        string ans="";
        char curr_carry = '0', old_carry='0';
        while(k>=0 || l>=0)
        {
            old_carry = curr_carry=='0'?'0':'1';
            char x = k>-1?a[k]:'0';
            char y = l>-1?b[l]:'0';
            char sum = (x=='1'||y=='1')?((x=='1'&&y=='1')?'0':'1'):'0';
            curr_carry = (x=='1'&&y=='1')?'1':'0';
            char totsum = (sum=='1'||old_carry=='1')?((sum=='1'&&old_carry=='1')?'0':'1'):'0';
            curr_carry = curr_carry=='0'?((sum=='1'&&old_carry=='1')?'1':'0'):'1';
            ans = totsum+ans;
            k--;
            l--;
        }
        old_carry = curr_carry;
        ans = old_carry=='1'?'1'+ans:ans;
        return ans;
    }

int main(){
    cout<<addBinary("10010110","1110101");
}