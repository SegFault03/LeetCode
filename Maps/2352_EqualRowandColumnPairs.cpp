#include<bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>colRecord, rowRecord;
        int n = 0;
        for(int row=0; row < grid.size(); row++)
        {
            string s ="";
            for(int column=0; column < grid.size(); column++)
            {    
                s += to_string(grid[row][column]);
                if(column < grid.size()-1) s+=" ";
            }
            rowRecord[s] = rowRecord.find(s)==rowRecord.end()?1:rowRecord[s]+1;
        }

        for(int column=0; column < grid.size(); column++)
        {
            string s ="";
            for(int row=0; row < grid.size(); row++)
            {    
                s += to_string(grid[row][column]);
                if(row < grid.size()-1) s+=" ";
            }
            colRecord[s] = colRecord.find(s)==rowRecord.end()?1:colRecord[s]+1;
        }

        for(auto [key, value]: rowRecord)
        {
            if(colRecord.find(key) != colRecord.end())
            {
                n += value * colRecord[key];
            }
        }
        return n;
    }

int main(){
    vector<vector<int>>test{{11,1},{1,11}};
    cout<<equalPairs(test);
}