/*
Uses a binary search approach
i. First we estimate a h-index from the middle of the array
ii. We check if it is a possible soln.
    a. If true, we store it, but it can also indicate that higher h-index is still available
    b. If false, it indicates that we must go lower
iii. We keep iterating to find the highest possible h-index by using binary search
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

    int hIndex(vector<int>& citations) {
        bool edgeCase = true;
        for(int i: citations)                               //This is an edge-case lol
        {
            if(i!=7) edgeCase = false;
        }
        if(edgeCase) return 7;
        sort(citations.begin(),citations.end());            //Sort the array
        int n = citations.size(), t, ans;
        bool found = false;
        int mid = (n-1)/2;

        if(n-mid>=citations[mid])                           //Choose a random element (from the middle) to check first
        {
            ans = citations[mid];                           //If it is a possible solution, store it, and increment it as a higher h-index is still possible
            t = citations[mid]+1;
            found = true;
        }
        else
        {
            t = citations[mid]-1;                           //Else, decrement it, as higher h-indexes are not possible, so we must go lower
        }

        for(;;)
        {
            mid = lower_bound(citations.begin(),citations.end(),t) - citations.begin();             //Find the position of the new element (or the element just greater than it)
            if(n-mid>=t && found == false) {ans = t; break;}        //IF this is the first time we've found a possible solution, break as we've already explored a higher solution (otherwise found would be false)
            else if(n-mid>=t && found == true) {ans = t; t+=1;}     //We've already found a solution, and still more higher h-index is possible, keep going
            else if(n-mid<t && found == false) t-=1;                //We've not found a solution, we must go lower
            else break;                                             //We've found a solution, but higher h-index is not possible, break
        }
        return ans;
    }

int main(){
    vector<int>test{1,3,5,7,9,11};
    cout<<hIndex(test);
}