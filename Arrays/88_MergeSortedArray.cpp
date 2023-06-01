#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t1=m-1,t2=n-1;
        for(int i=(m+n)-1;i>=0;i--)
        {
            if(t1==-1){
            nums1[i] = nums2[t2];
            t2--;
            }
            else if(t2==-1)
            {
                nums1[i] = nums1[t1];
                t1--;
            }
            else
            {
                if(nums1[t1]>nums2[t2])
                {
                    nums1[i] = nums1[t1];
                    t1--;
                }
                else
                {
                    nums1[i] = nums2[t2];
                    t2--;
                }
            }
        }
    }

int main(){
    vector<int>a{2,5,8,0,0,0}, b{1,4,11};
    merge(a,3,b,3);
    for(auto i: a) cout<<i<<" ";
}

