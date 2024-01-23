#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
vector<unordered_set<char>> freq;
    int lmax = 0;

    bool check(int i, unordered_set<char> &sen) {
        for(auto ch: freq[i]) {
            if(sen.find(ch)!=sen.end())
                return false;
        }
        return true;
    }

    void backtrack(int j, vector<string>& arr, unordered_set<char> &sen) {
        if(j==arr.size())
        lmax = sen.size()>lmax? sen.size(): lmax;
        else {
            for(int i=j;i<arr.size();i++) {
                unordered_set<char>rec = sen;
                if(freq[i].find('$')==freq[i].end()) {
                    if(check(i,sen))
                    { 
                        for(char ch: arr[i]) {
                            rec.insert(ch);
                        }
                    }
                    backtrack(i+1, arr, rec);
                }
            }
            lmax = sen.size()>lmax? sen.size(): lmax;
        }
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        freq = vector<unordered_set<char>>(n, unordered_set<char>());
        for (int i = 0; i < n; i++) {
            for (char ch : arr[i]) {
               if(freq[i].find(ch)==freq[i].end())
               freq[i].insert(ch);
               else
               freq[i].insert('$');
            }
        }
        unordered_set<char>sen;
        backtrack(0, arr, sen);
        return lmax;
    }



int main(){
    vector<string>test{"aa","bb","cc"};
    cout<<maxLength(test);
}