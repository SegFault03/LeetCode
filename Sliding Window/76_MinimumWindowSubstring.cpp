#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * Sliding window technique:
 * 1. Maintain left and right pointers where window streches from left pointer to right pointer
 * 2. Scan the array, incrementing the right pointer until window contains all characters (with
 * the same frequency) is present
 * 3. Now increment left pointer until l==r or until window does not contain all the chars. 
 * 4. Repeat step 2-3 until right pointer reaches end of string 
*/

    pair<int, int> updateMin(pair<int, int>& minP, int l, int r) {
        if ((minP.second - minP.first) > (r - l)) {
            minP.first = l;
            minP.second = r;
        }
        return minP;
    }

    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        unordered_map<char, int> store, track;
        pair<int, int> minP = {0, 99999};
        int rem = 0;
        for (char i : t) {
            store[i]++;
            rem++;
        }
        int l = 0, r;

        //set left pointer to the index where the first char that belongs to t is present
        while (store.find(s[l]) == store.end() && l < s.length())
            l++;

        //this will be true only if not a single common char is present
        if (l == s.length())
            return "";
        track[s[l]] = 1;
        rem--;

        //this will be true only if t is equal to 1, in that case there can be no smaller string
        //be present, and thus return immediately
        if (rem == 0)
            return t;
        
        r = l + 1;

        while (r < s.length()) {
            if (rem == 0) {
                minP = updateMin(minP, l, r);
                while (l < r) {
                    if (store.find(s[l]) != store.end()) {
                        
                            track[s[l]]--;

                            //break loop if window does not contain all the chars or some char 
                            //has a lower freq compared to t
                            if (track[s[l]] == 0) {
                                track.erase(s[l]);
                                l++;
                                rem++;
                                break;
                            }
                        

                            if (track[s[l]] < store[s[l]]) {
                                l++;
                                rem++;
                                break;
                            }
                    }

                    l++;
                    //update minP
                    if (rem == 0) {
                        minP = updateMin(minP, l, r);
                    }
                }
            }

            if (store.find(s[r]) != store.end()) {
                if (track.find(s[r]) == track.end())
                    track[s[r]] = 1;
                else
                    track[s[r]]++;
                    
                //rem will only decrement if freq of some char in window is less than or
                //equal to the same char in t. This is because in case some char in window
                //has more freq than the same char in t, it won't actually decrease the
                //remaining chars that need to be found    
                if (track[s[r]] <= store[s[r]])
                    rem--;
            }

            r++;
        }
        if (rem == 0) {
            minP = updateMin(minP, l, r);
            while (l < r) {
                if (store.find(s[l]) != store.end()) {
                    {
                        track[s[l]]--;
                        if (track[s[l]] == 0) {
                            track.erase(s[l]);
                            l++;
                            rem++;
                            break;
                        }
                    }
                    if (track[s[l]] < store[s[l]]) {
                        l++;
                        rem++;
                        break;
                    }
                }
                l++;
                if (rem == 0) {
                    minP = updateMin(minP, l, r);
                }
            }
        }
        if (minP.first == 0 && minP.second == 99999)
            return "";
        return minP.first < minP.second
                   ? s.substr(minP.first, minP.second - minP.first)
                   : "";
    }


int main(){
    string s = "babb", t = "baba";
    cout<<minWindow(s, t);
}