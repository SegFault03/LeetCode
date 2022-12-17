#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_set<int>track;
        for(int i: arr)
        {
            freq[i]++;
        }
        auto itr = freq.begin();
        while(itr!=freq.end())
        {
            int psize = track.size();
            track.insert(itr->second);
            if(track.size()==psize)
            return false;
            itr++;
        }
        return true;
    }

int main(){
    vector<int>test{1,2,2,1,1,3};
    cout<<uniqueOccurrences(test);
}