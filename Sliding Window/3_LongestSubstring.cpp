/*
The general concepts used in sliding window applies here as well. 
We make use of two pointers. When we encounter a duplicate char, we set the
lp to an index after the first occorence of the duplicate char.
E.g: avianj
lp = 0, rp = 1, l = 1, a
rp = 2, l = 2, av
rp = 3, l = 3, avi
rp = 4, duplicate found, set lp to 1 as a occurs first at index = 0
ACCEPTED SOLUTION
*/
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int lp = 0, rp = 1, l=1, max = -99999;
        unordered_map<char,int>freq;                        //map used for tracking the index of each char
        freq[s[0]] = 0;
        while(rp < s.length())
        {
            if(freq.find(s[rp])!=freq.end())                //check for duplicates
            {
                max = l > max? l: max;                      //initialize length
                lp = freq[s[rp]];                           //get the index of the duplicate char
                lp++;                                       //start the new window from immediately after the duplicate char
                freq.clear();                               //clear the map
                l = 0;
                while(lp < rp)                              //until lp<=rp, normal sliding window concept
                {
                    freq[s[lp]] = lp;                       //update the map again with chars of the new window
                    lp++;
                    l++;
                }
                l++;
            }
            else l++;                               
            freq[s[rp]] = rp;                               //update the map with the current character
            rp++;
        }
        max = l > max? l: max;                              //update max with new length after loop exits (as l>max after loop ends)
        return max;
    }


int main(){
    string s = "anviaj";
    cout<<lengthOfLongestSubstring(s);
}