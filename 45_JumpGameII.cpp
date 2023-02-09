#include<bits/stdc++.h>
using namespace std;
/*
NOTES:
Uses a BFS approach to search for the minimum number of edges needed to reach destination node (nums.size()-1) 
from root node (0).

Maintain a hashmap that stores the nodes that have been visited and their minimum edge distance from the root node.
Algorithm:
1. Insert the root node 0 into the dict and set its distance to 0. Also push it to the queue.
2. Until queue is empty:
3. Pop the first element from the queue
4. Check if the popped node is the destination node
   IF TRUE: Compare it against a minimum distance last encountered and update accordingly. Continue the loop.
   ELSE:
        i. For each of its neighbour that is either not in the dictionary, or whose edge distance is 
        greater than the current edge distance, push it into the queue and update the dictionary. This
        is necessary because if the edge distance of some node is updated, the new edge distance of its
        neighbours will need to be updated as well, and hence it must be pushed to the queue again, even 
        if has been visited before.
5. Return min 

Alternative greedy soln: https://leetcode.com/problems/jump-game-ii/solutions/3076867/jump-game-ii/
*/

int jump(vector<int>& nums) {
        queue<int>queueStore;
        unordered_map<int,int>vis;
        queueStore.push(0);
        vis[0]=0;
        int min = 99999;
        while(!queueStore.empty())
        {
            int root = queueStore.front();
            queueStore.pop();
            if(root == nums.size()-1)
            {
                min = vis[root]<min?vis[root]:min;
                continue;
            }
            for(int j = 1;j <= nums[root];j++)
            {
                int child = root+j>nums.size()-1?nums.size()-1:root+j;
                if(vis.find(child)==vis.end())
                {
                    vis[child] = vis[root]+1;
                    queueStore.push(child);
                }
                else
                {
                    if(vis[root]+1<vis[child])
                    {
                        vis[child] = vis[root]+1;
                        queueStore.push(child);
                    }
                }
            }
        }
        return min;
    }

int main(){
    vector<int>test{2,3,0,1,4};
    cout<<jump(test);
}