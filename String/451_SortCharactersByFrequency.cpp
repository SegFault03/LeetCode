#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
bool sortFn(pair<int,int>a, pair<int,int>b){
    return a.second>b.second;
}

string frequencySort(string s) {
        vector<pair<char,int>>arr(62,pair<char,int>('x', 0));
        for(int i=0;i<62;i++){
            if(i>=0 && i<=25)
            arr[i].first = (char)(65+i);
            else if(i>=26 && i<=51)
            arr[i].first = (char)(97+(i-26));
            else
            arr[i].first = (char)(48+(i-52));
        }
        for(char ch: s){
            if(ch>=65 && ch<=90)
            arr[0+(ch-65)].second++;
            else if(ch>=97 && ch<=122)
            arr[26+(ch-97)].second++;
            else
            arr[52+(ch-48)].second++;
        }
        sort(arr.begin(), arr.end(), sortFn);
        int i = 0;
        string ans = "";
        while(i<62 && arr[i].second>0){
            for(int j=1;j<=arr[i].second;j++)
            ans+=arr[i].first;
            i++;
        }
        return ans;
    }


int main(){
    string s = "aaaAAb1111";
    frequencySort(s);
}