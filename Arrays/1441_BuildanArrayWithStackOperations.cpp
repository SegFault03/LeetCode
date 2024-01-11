#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
vector<string> buildArray(vector<int>& target, int n) {
        int p = -1, i = 1, k = target.size()-1;
        vector<string>ops;
        while(p<k && i<=n){
            if(target[p+1]==i)
            {
                ops.push_back("Push");
                p++;
            }
            else
            {
                ops.push_back("Push");
                ops.push_back("Pop");
            }
            i++;
        }
        return ops;
    }


int main(){
    vector<int>test{1,3};
    buildArray(test,3);
}