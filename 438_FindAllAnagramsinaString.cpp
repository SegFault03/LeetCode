#include<bits/stdc++.h>
using namespace std;

/*
NOTES: Uses a sliding window approach
An anagram is essentially a possible permutation of a given word. For
example cba is an anagram of abc. So are acb, bac, etc.
One way of checking for anagram is to check if the frequency of the characters
appearing in the word to be checked is the same as the original word.
For example in the word cba, c, b and a all appear 1 time. This matches with
the character frequency of abc. Thus cba is an anagram.

Here we find all positions of the anagram of some word in some other word
using the sliding window approach. The length of the window is the size
of the word whose anagrams are to be searched for. Every time we 'slide'
the window, we increment the frequency of the new character encountered by 
the window and decrement the frequency of the character that was last 
present in the window. After every such operation we check if the 
new word is an anagram or not.
*/

vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
        return vector<int>();
        int alpha[26]={0},ori[26]={0}, l = p.length();
        vector<int>ans;
        
        //Store the char frequencies of the original word
        for(auto i: p)
        ori[i-97]++;
        
        //Calculate the char frequencies of the first window
        for(int i=0;i<l;i++)
        alpha[s[i]-97]++;
        bool first = true;
        
        //Check if the word in the first window is an anagram or not
        for(int i=0;i<26;i++)
        {
            if(ori[i]!=alpha[i])
            {
                first = false;
                break;
            }
        }
        if(first)
        ans.push_back(0);
        
        //Start scanning the remaining word
        for(int i=l;i<s.length();i++)
        {
            first = true;
            alpha[s[i-l]-97]--;                 
            alpha[s[i]-97]++;
             for(int i=0;i<26;i++)
            {
                if(ori[i]!=alpha[i])
                {
                    first = false;
                    break;
                }
            }
            if(first)
            ans.push_back(i-l+1);
        }
        return ans;
    }

int main(){
    for(auto i: findAnagrams("abcbacfgcab","abc"))
    cout<<i;
}