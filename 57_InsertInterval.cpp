#include<bits/stdc++.h>
using namespace std;
//ACCEPTED SOLUTION
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>temp, ans;
        bool inserted = false;

        for(int i=0; i<intervals.size(); i++)                                   //insert the interval
        {
            if(inserted) temp.push_back(intervals[i]);
            else
            {
                if(newInterval[0]<=intervals[i][0])
                {
                    temp.push_back(newInterval);
                    temp.push_back(intervals[i]);
                    inserted = true;
                }
                else
                temp.push_back(intervals[i]);
            }
        }
        if(!inserted)
        temp.push_back(newInterval);

        int lb = intervals[0][0], ub = intervals[0][1];
        for(int i=1; i<intervals.size(); i++)                                 //merge the intervals using standard logic
        {  
            if(intervals[i][0]<=ub)
            ub = max(ub, intervals[i][1]);
            else{
            ans.push_back(vector<int>{lb,ub});
            ub = intervals[i][1];
            lb = intervals[i][0];
            }
        }
        ans.push_back(vector<int>{ub,lb});
        return ans;
    }

int main(){
    vector<vector<int>>test{{1,3},{6,9}};
    vector<int>test2{6,11};
    vector<vector<int>>out(insert(test,test2));
    for(auto i: out)
    cout<<i[0]<<" "<<i[1]<<endl;
}