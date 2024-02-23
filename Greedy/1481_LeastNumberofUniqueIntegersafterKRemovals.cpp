#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>freq;
        auto comp = [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        };
        vector<pair<int,int>>holder;
        for(int i: arr)
        freq[i]++;
        for(auto [key,value]: freq)
        holder.push_back({key,value});
        sort(holder.begin(), holder.end(), comp);
        int i = 0, hsize = holder.size(), deleted = 0;
        while(i<holder.size() && k>0){
            if(holder[i].second<=k)
            {
                k-=holder[i].second;
                deleted++;
            }
            else
            break;
            i++;
        }
        return hsize-deleted;
    }


int main(){
    vector<int>t{4,3,1,1,3,3,2};
    int k = 3;
    cout<<findLeastNumOfUniqueInts(t, k);
}