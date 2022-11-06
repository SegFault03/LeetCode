#include<bits/stdc++.h>
using namespace std;

vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ball;
        int i,j,k,m=grid.size(),n=grid[0].size();
        for(i=0;i<n;i++)
        ball.push_back(i);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int pos = ball[i];
                k = grid[j][pos];
                if(pos+k>=0 && pos+k<n)
                {
                    if(grid[j][pos+k]==k)
                    ball[i]+=k;
                    else
                    {
                        ball[i]=-1;
                        break;
                    }
                }
                else
                {
                    ball[i]=-1;
                    break;
                }
            }
        }
        return ball;
}

int main(){
    vector<vector<int>>test{{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    vector<int>out = findBall(test);
    for(auto i: out)
    cout<<i<<" ";
}