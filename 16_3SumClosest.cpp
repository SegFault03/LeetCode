#include <bits/stdc++.h>
using namespace std;
//Implemented using two-pointers
//Time Complexity: O(n^2)

int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j,k,n=nums.size();
        int sum=nums[0]+nums[1]+nums[nums.size()-1];
        int diff=abs(target-sum);
        int rsum=sum;
        for(int i=0;i<nums.size();i++)
        {
            j=i+1;
            k=n-1;
            while(k>j)      //Find the viable sum containing a[i]
            {
                sum=nums[i]+nums[j]+nums[k];    
                if(abs(target-sum)<diff)
                {
                    diff=abs(target-sum);
                    rsum=sum;
                }

                if(sum>target)
                k--;

                else if(sum<target)
                j++;

                else
                return target;
            }

        }
        return rsum;
}

int main()
{
    vector<int>test{-6,4,-5,3,-2,1,-3};
    cout<<threeSumClosest(test,5);
}

//NOTES:
/*
Algo:
For a given element, say i, find the closest sum from the pool of elements not having i, and then add i to that
sum. Check how close it is. Use concept of 2 pointers to update pointers.
Now, since all viable combinations that contain i has already been found, do not consider i anymore.(As for some
element j, finding the closest sum from a pool of elements that also contain i will simply breed redundancy, as
the sum j+i+some number has already been considered before.)
Continue this for i<j<=n-1
*/