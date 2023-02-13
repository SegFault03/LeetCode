#include<bits/stdc++.h>
using namespace std;
/*NOTES:
This particular problem uses BFS strategy to search for the shortest alternating path.
The choice of BFS is made as we need to keep track of all possible paths from a given
node and update distances accordingly, so it is better if we go level by level.(as 
in this case it will be easier to update the distance, we only need to increment one 
every level)

In this case the queue stores a two-bit int vector, one storing the node itself and the
second storing the color of the edge which lead to it (before it was pushed into the 
queue). Every time we do the pop operation, we check the color of the edge that led to 
node that was popped, and push the neighbours of the opposite color that are yet to be 
visited into the queue. 

One more important thing to keep in mind is that since the given graph is not a simple 
graph, there might be parallel edges of the opposite color for a given node. And since 
we need to visit every edge, and not every node, instead of using a single hashmap to 
record the nodes visited, we'll be using two separate hashmaps for storing the nodes 
visited using some particular color. For example, say there are two edges leading to 
node '1': one red the other blue. When we reach '1' using the red edge, we only update 
the map storing the visited nodes that are reachable using red edges, and not the map 
storing the visited nodes that are reachable using blue edges. We do the opposite when 
we visit the same node using a blue edge.

As for storing the minimum distance, each time we find a node that has already been 
visited, we check if the new distance is shorter than the distance stored, if so, 
we update its distance and push it into the queue again (as the distances of all of its 
neighbours will have to be updated as well.)

We can guarantee that the queue will be empty after some time and no cycle will be formed
as eventually distances can no longer be minimized anymore than they currently are and 
thus no more nodes will pushed into the queue.
*/

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<int>>blueMap,redMap;
        unordered_map<int,int>redVis,blueVis;
        queue<vector<int>>bfs;
        vector<int>ans(n,-1);
        for(int i = 0; i<redEdges.size();i++)
        redMap[redEdges[i][0]].push_back(redEdges[i][1]);           
        for(int i = 0; i<blueEdges.size();i++)                      
        blueMap[blueEdges[i][0]].push_back(blueEdges[i][1]);        
        for(int des=0;des<n;des++)                                  
        {
            int min = 99999;
            redVis.clear(); blueVis.clear();                        //clear both the maps when starting out
            redVis[0]=0; blueVis[0]=0;
            bfs.push(vector<int>{0,0});                             
            while(!bfs.empty())
            {
                vector<int> root = bfs.front();
                bfs.pop();
                if(root[0]==des)                                    //check if the popped node is the destination
                {
                    if(root[1]==1)
                    min = min>redVis[root[0]]?redVis[root[0]]:min;  //Check how the node was reached (red/blue) and update distance accoringly                  
                    else
                    min = min>blueVis[root[0]]?blueVis[root[0]]:min;
                    continue;
                }
                if(root[1]==0)                                            
                {
                    for(auto child: redMap[root[0]])                //push all the nodes that are reachable from either blue or red edges in case 
                    {                                               //the current node is the source node Note that in such a case, the same node 
                        redVis[child] = 1;                          // may be visited twice, and hence we need to use two different hashmaps.
                        bfs.push(vector<int>{child,1});
                    }
                    for(auto child: blueMap[root[0]])
                    {
                        blueVis[child] = 1;
                        bfs.push(vector<int>{child,2});
                    }
                }
                else if(root[1]==1)                                 //if it was reached using a red edge, push all its blue neighbours
                {                                                   //also check if it's distance can be minimized
                    for(auto child: blueMap[root[0]])
                    {
                        if(blueVis.find(child)==blueVis.end() || blueVis[child] > redVis[root[0]]+1)            
                        {
                            blueVis[child] = redVis[root[0]]+1;
                            bfs.push(vector<int>{child,2});
                        }
                    }
                }
                else                                                //do the opposite if was reached using a blue edge
                {
                    for(auto child: redMap[root[0]])
                    {
                        if(redVis.find(child)==redVis.end() || redVis[child] > blueVis[root[0]]+1)
                        {
                            redVis[child] = blueVis[root[0]]+1;
                            bfs.push(vector<int>{child,1});
                        }
                    }
                }
            }
            if(min!=99999)
            ans[des] = min;
        }
        return ans;
}

int main(){
    vector<vector<int>>red{{0,1},{1,2},{2,3},{3,4}},blue{{1,2},{2,3},{3,1}};
    int n = 5;
    for(auto i: shortestAlternatingPaths(n,red,blue))
    cout<<i<<" ";
}