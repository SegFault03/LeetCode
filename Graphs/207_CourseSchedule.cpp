#include<bits/stdc++.h>
//CCEPTED SOLUTION
using namespace std;

    bool finishCourse(int currCourse, unordered_map<int,vector<int>>&g, unordered_map<int, bool>&vis)
    {
        if(g.find(currCourse)==g.end())
        {
            vis[currCourse] = true;
            return true;
        }
        for(int prereq: g[currCourse])
        {
            if(vis.find(prereq)==vis.end())
            {
                vis[prereq] = false;
                if(!finishCourse(prereq, g, vis))
                {
                    vis[currCourse] = false;
                    return false;
                }
            }
            else
            {
                if(!vis[prereq])
                {
                    vis[currCourse] = false;
                    return false;
                }
            }
        }
        vis[currCourse] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>graph;
        unordered_map<int,bool>vis;
        for(auto cell: prerequisites)
        graph[cell[0]].push_back(cell[1]);
        bool flag = true;
        for(int i=0; i<numCourses; i++)
        {
            vis[i] = false;
            flag = finishCourse(i, graph, vis);
            if(!flag) return false;
        }
        return true;
    }

int main(){

}