/**
 * Another application of topological sorting via DFS
 * Here we have to find the topological ordering
 * Also another application of checking if  agiven graph contains a cycle
 * If graph has a cycle -> No topological sorting/ordering is possible
*/
#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
    vector<int> topoSort(int courseNo,unordered_map<int,vector<int>>&adjList,//Uses standard DFS logic to check if a cycle exists   
        unordered_map<int,int>&vis)
        {
            vector<int>ans{};
            vis[courseNo] = 0;                                              //signifies node is currently being processed
            for(int preReq: adjList[courseNo])
            {
                if(vis.find(preReq)==vis.end())                             
                {       
                    vector<int>res = topoSort(preReq, adjList, vis);        
                    if(res.size()==0) return vector<int>();                 //will only return an empty vector if there is a cycle
                    ans.insert(ans.end(),res.begin(),res.end());            //append returned vector to the topological order
                }
                else
                {
                    if(vis[preReq]==0)                                      //Neighbouring node also being processed -> There exists a cycle
                    return vector<int>();
                }
                
            }
            vis[courseNo] = 1;                                              //mark the node as being fully processed
            ans.push_back(courseNo);                                        //finally, append the current node to the topological order
            return ans;
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adjList;
        unordered_map<int,int>vis;
        vector<int>ans{};
        int courseNo = 0;
        for(int i=0;i<prerequisites.size();i++)
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        while(courseNo<numCourses)
        {
            if(vis.find(courseNo)==vis.end())                               //visit all unvisited nodes
            {
                vector<int>res = topoSort(courseNo, adjList, vis);
                if(res.size()==0) return vector<int>();
                ans.insert(ans.end(),res.begin(),res.end());
            }
            courseNo++;
        }
        return ans;
    }


int main(){
    string test = "[[1,0],[2,0],[3,1],[3,2]]";
    vector<vector<int>>testv=VectorParser::twoDArrayParser(test);
    VectorParser::printOneDArray(findOrder(4,testv));
}