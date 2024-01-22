#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
class Solution {
public:
    static bool sortFn(pair<int,int>a, pair<int,int>b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>arr;
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int i: nums)
        freq[i]++;
        for(auto [key,v]: freq)
        arr.push_back({key,v});
        sort(arr.begin(), arr.end(), sortFn);
        for(int i=0;i<k;i++)
        ans.push_back(arr[i].first);
        return ans;
    }
};



int main(){
}