/*
SIMPLE BFS APPROACH TO FIND 'REACHABILITY' OF EACH BOMB
Algorithm:
i. Select an arbitary bomb that has not been visited (or detonated) and push it to into the queue
ii. while queue is empty:
iii.    pop an element from the queue, name it 'root'
iv.     For each bomb in bombs:
v.          check if bomb 'i' can be reached from root (if bomb 'i' lies within the range of root)
vi.         if true, and if the bomb has not been visited before, push it into the queue, mark it as visited
vii.        Set count: count+1
viii.Update max according to count, and reinitialize count = 0

The idea is that we only perform a bfs search on those bombs that have never been visited before, and count the 
number of nodes we can visit in a single search. There is no need to perform BFS for each node as nodes which have
been visited before already contribute to max, and therefore they do not need to be counted again. Only the nodes that
are yet to be visited need to be traversed, to check if they can reach a greater number of nodes than what is currently 
possible.
ACCEPTED SOLUTION.
*/


#include<bits/stdc++.h>
using namespace std;

int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int>vis(n,-1);
        int max = -99999, c;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                vector<int>lvis(n,-1);                                          //there needs to be a separate array to record nodes visited in a single search
                c = 1;                                                          //This is because in each search, we count the no. of nodes
                queue<int>queue;
                queue.push(i);
                lvis[i] = 1;                
                vis[i] = 1;
                while(!queue.empty())
                {
                    int root = queue.front();
                    queue.pop();
                    int x1 = bombs[root][0], y1 = bombs[root][1], r = bombs[root][2];
                    for(int j=0;j<n;j++)
                    {
                        int x2 = bombs[j][0], y2 = bombs[j][1];
                        double dis = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
                        if(j!=root && dis<=r)
                        {
                            if(lvis[j]==1) continue;
                            lvis[j] = 1;                                    
                            vis[j] = 1;
                            c++;
                            queue.push(j);
                        }
                    }
                }
                max = c>max?c:max;
            }
        }
        return max;
    }

int main(){
    vector<vector<int>>test{{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    cout<<maximumDetonation(test);
}