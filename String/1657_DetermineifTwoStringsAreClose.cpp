#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLN.
bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())                       //check length
            return false;
        unordered_map<char, int> a, b;
        unordered_map<int, int> f1, f2;
        for (int i = 0; i < word1.length(); i++) {
            a[word1[i]]++;
            b[word2[i]]++;
        }
        for (auto [key, val] : a)
            f1[val]++;
        for (auto [key, val] : b)
            f2[val]++;
        for (auto [key, val] : a) {                                //check if both words have the exact same set of letters (no extra chars in either word, no less)
            if(b.find(key)==b.end())
            return false;
            else
                b.erase(key);
        }
        if(b.size()!=0)
            return false;
        for (auto [key, val] : f1) {                                //check if the frequency distribution of both words is same
            if(f2.find(key)==f2.end())
            return false;
            else
            {
                if(f2[key]!=f1[key])
                    return false;
                f2.erase(key);
            }
        }
        if(f2.size()!=0)
            return false;
        return true;
    }


int main(){
}