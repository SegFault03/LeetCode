#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLN.
*/
int lengthOfLIS(vector<int>& nums) {
    vector<int>subq;
    subq.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>subq[subq.size()-1])
          subq.push_back(nums[i]);
          else
          {
            int p = lower_bound(subq.begin(),subq.end(),nums[i])-subq.begin();
            subq[p] = nums[i];
          }
        }
        return subq.size();  
    }


int main(){
    string s = "[7,7,7,7,7,7,7]";
    vector<int>test = VectorParser::oneDArrayParser(s);
    cout<<lengthOfLIS(test);
}