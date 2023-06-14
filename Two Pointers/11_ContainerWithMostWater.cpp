/*
Another sample problem for demonstrating the use of 2 pointers.
Here, we have to maximize the area of the rectangle.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        double max = -99999, lp = 0, rp = height.size()-1;          //initially, set lp to 0 and rp to arr.size-1
        while(rp > lp)                                              //this will cover the entire array
        {
            double area = (rp - lp) * min(height[rp],height[lp]);   //the water aspect of the problem means we will have to consider the lower height
            max = area > max?area:max;                              //update max
            if(height[lp] > height[rp]) rp--;                       //since we have to maximize area, we shall always select the index containing the highest number
            else lp++;                                              //At any point, we must keep in mind that we have already explored all indexes > rp, and
        }                                                           //...all indexes < lp. This is the very essence of 2 pointers.        
        return max;
    }

int main(){
    vector<int>test{5,3,2,1,7,6,3,2};
    cout<<maxArea(test);
}