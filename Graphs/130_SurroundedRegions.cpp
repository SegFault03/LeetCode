#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLTUION
void bfs(vector<vector<char>>& board, vector<vector<int>>&vis, int i, int j)
    {
        int m = board.size(), n = board[0].size();
        stack<pair<int,int>>stack;
        vis[i][j]=1;
        stack.push({i,j});
        board[i][j] = 'M';
        while(!stack.empty())
        {
            int row = stack.top().first;
            int col = stack.top().second;
            stack.pop();
            if(row-1>=0 && (board[row-1][col]=='O' && vis[row-1][col]!=1))
            {
                vis[row-1][col] = 1;
                board[row-1][col]= 'M';
                stack.push({row-1,col});
            }
            if(col-1>=0 && (board[row][col-1]=='O' && vis[row][col-1]!=1))
            {
                vis[row][col-1] = 1;
                board[row][col-1]= 'M';
                stack.push({row,col-1});
            }
            if(col+1<n && (board[row][col+1]=='O' && vis[row][col+1]!=1))
            {
                vis[row][col+1] = 1;
                board[row][col+1]= 'M';
                stack.push({row,col+1});
            }
            if(row+1<m && (board[row+1][col]=='O' && vis[row+1][col]!=1))
            {
                vis[row+1][col] = 1;
                board[row+1][col]= 'M';
                stack.push({row+1,col});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0; i<n;i++)
        {
            if(vis[0][i]!=1 && board[0][i]=='O')
            {
                bfs(board,vis,0,i);
            }
            if(vis[m-1][i]!=1 && board[m-1][i]=='O')
            {
                bfs(board,vis,m-1,i);
            }
        }
        for(int i=0; i<m;i++)
        {
            if(vis[i][0]!=1 && board[i][0]=='O')
            {
                bfs(board,vis,i,0);
            }
            if(vis[i][n-1]!=1 && board[i][n-1]=='O')
            {
                bfs(board,vis,i,n-1);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                if(board[i][j]=='M')
                board[i][j]='O';
            }
        }

    }



int main(){
    vector<vector<char>>test{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    solve(test);
}