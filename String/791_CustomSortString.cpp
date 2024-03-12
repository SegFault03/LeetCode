#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLN.
*/
vector<int>wmap;
bool custSort(char a, char b)
{
    return wmap[a-97]<wmap[b-97];
}
string customSortString(string order, string s) {
        wmap = vector<int>(26,999);
        for(int i=0;i<order.length();i++)
        {
            cout<<order[i]<<endl;
            wmap[order[i]-97] = i;
        }
        sort(s.begin(), s.end(), custSort);
        return s;
    }

int main(){
    string order = "cba", s = "abcd";
    cout<<customSortString(order,s);
}