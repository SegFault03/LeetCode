#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    vector<vector<char>>matrix(1,vector<char>(numRows,'$'));
    string ans="";
    int i=0,j=0,col=0;
    while(i<s.length())
    {
        int row = -1;
        while(++row<numRows)
        matrix[col][row] = s[i++];
        col++;
        row-=2;
        while(row>0)
        {
            if(col+1>matrix.size())
            matrix.push_back(vector<char>(numRows,'$'));
            char temp = s[i];
            matrix[col][row] = temp;
            i++;
            row--;
            col++;
        }
        matrix.push_back(vector<char>(numRows,'$'));
    }
    i=0;
    for(i=0;i<numRows;i++)
    {
        for(j=0;j<matrix.size();j++)
        {
            if(matrix[j][i]>=65 && matrix[j][i]<=97)
            ans+=matrix[j][i];
        }
    }
    return ans;  
    }

int main(){
    cout<<convert("A",1);
}