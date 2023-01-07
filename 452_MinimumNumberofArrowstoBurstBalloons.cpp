#include<bits/stdc++.h>
using namespace std;
/*
NOTES:
We've to find the number of overlapping points. No. of arrows required =  No. of overlapping points
Obviously, to do that we need to sort the array, in terms of the second dimension.
This is because condition for two ballons [x1,y1] and [x2,y2] to overlap
where y1 <= y2 is x2<=y1. The first condition y1<=y1 can be enforced by sorting the ballons
on the basis of the second dimensions.

Greedy Strategy:
We compare two consecutive ballons, check if they are overlapping or not
IF true, this means both can be hit with one arrow
ELSE we need a new arrow to hit the second baloon
We do this for all the baloons. 
*/


    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
        return 0;
        sort(points.begin(),points.end(),compare);
        int count=1;                        //At least one arrow is needed in all cases
        int arrow = points[0][1];           //We take the second dimension as the position to
                                            //where the arrow strikes as it will maximize the area 
                                            //covered
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=arrow)         
            continue;
            else
            {
                arrow = points[i][1];       //Set new arrow striking position if two baloons
                                            //are not overlapping and we need a new arrow.
                count++;
            }
        }
        return count;
    }

int main(){
    vector<vector<int>>test{{10,16},{2,8},{1,6},{7,12}};
    cout<<findMinArrowShots(test);
}