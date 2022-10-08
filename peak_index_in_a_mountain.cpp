#include <bits/stdc++.h>
using namespace std;

//while using binary search, avoid using low<=high condition as it can create 
//indexes like mid=-1 if not too careful
//Instead use low<high and high=mid, low=mid

int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1,mid=0;
        while(low<high)
        {
            mid=floor((low+high)/2);
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid+1])
                high=mid;
            else
                low=mid;
        }
        return 0;
    }

int main()
{
    vector<int> array={0,1,2,3,4,10,9,8,7,6,5};
    cout<<peakIndexInMountainArray(array);
}