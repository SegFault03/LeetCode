/*
Simple BFS strategy to find the maximum path sum starting from the root to a leaf node for a tree
(DFS strategy is also applicable in this case)

The strategy is quite simple:
i. Start from the root node (the one with headID), and keep track of the cumulative informTime and a max value.
ii. When pushing a new node into the queue, add informTime[root] with cumulTime in order to calculate the total
path sum upto that point, which is actually the total time it will take to inform the employee.
iii. Return the maximum path sum, as that will be the longest it wil ltake to inform all employees.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>relations;
        int max = 0;
        queue<pair<int,int>>queue;
        for(int i=0;i<n;i++){                                                                   //construct the edge-map (adj.list)
            if(manager[i]!=-1)
            relations[manager[i]].push_back(i);
        }
        queue.push({headID,0});                                                                 //initially, path sum = 0
        while(!queue.empty())
        {
            pair<int,int>boss = queue.front();
            queue.pop();
            int index = boss.first, cumulTime = boss.second;
            for(int i: relations[index])
            queue.push({i,cumulTime + informTime[index]});                                     //calculate the total path sum upto that point
            max = cumulTime + informTime[index]>max?cumulTime + informTime[index]:max;         //Update max path sum
        }
        return max;
    }

int main(){
}