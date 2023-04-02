#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
long long int hours = 0, n = piles.size();
        sort(piles.begin(),piles.end());
        long long int lb = 1, ub = piles[n-1], mid,lastValid;
        while(lb<=ub)
        {
            mid = lb + (ub - lb) / 2;
            long long int pos = upper_bound(piles.begin(),piles.end(),mid)-piles.begin();
            for(int i = pos;i<n;i++)
            {
                double tot = double(piles[i])/double(mid);
                hours+=ceil(tot);
            }
            hours+=(pos);
            if(hours>h)
            lb = mid + 1;
            else 
            {
                ub = mid - 1;
                lastValid = mid;
            }
            hours = 0;
        }
        return lastValid; 
    }

int main(){
    vector<int>test{30,11,23,4,20};
    cout<<minEatingSpeed(test,7);
}