#include<bits/stdc++.h>
using namespace std;

//NOTES: 
/*
This is essentially an algorithm to check if a graph is bipartite or not. for every pair [a,b] 
in dislikes[], a and b can be treated as a vertex, and an edge a -> b can be imagined. However, for the
sake of simplicity, we shall be considering an undirected graph instead of a directed graph. This 
is because two people a, b cannot stay together if a dislikes b, or if b dislikes a. In other words, the 
edge a -> b implies the vertex a cannot be part of the same set as b, and therefore the an equivalent edge 
b -> a can be created and it would not change the problem. Even if one cosiders the bipartite problem, it can
be easily seen that considering an undirected graph instead of a directed one does not make a difference, it
only makes the problem more easier to solve (as we will see later).

ALGORITHM:
We shall be using the simple DFS algo and a variant of the 2-coloring algorithm to check if the
given graph is bipartite:
(1) Choose an unvisited vertex and assign it some color before pushing it to a stack
(2) While the stack is not empty:
    (i) Pop a vertex and store its color
    (ii) Check if any of its neighbouring (visited) vertices have the same color as itself, if TRUE return FALSE
    (iii) Assign the opposite color to all of its neighbouring unvisited vertices and push them to the stack.
The graph is bipartite only if it is possible to any one of two colors to all the vertices. 
*/

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    if(n==0)
    return true;
    unordered_map<int,vector<int>>edges;                                //Adjacency list
    unordered_map<int,int>colors;                                       //Stores the visited vertices and their colors
    stack<int>stack;
    for(int i=0;i<dislikes.size();i++)                                  //Creates the adjacency list
    {
        if(edges.find(dislikes[i][0])==edges.end())
        edges[dislikes[i][0]]={};

        if(edges.find(dislikes[i][1])==edges.end())
        edges[dislikes[i][1]]={};

        edges[dislikes[i][0]].push_back(dislikes[i][1]);
        edges[dislikes[i][1]].push_back(dislikes[i][0]);
    } 

    for(auto i = edges.begin();i != edges.end();i++)                  //This is done in case the given graph is not a connected graph
    {
        if(colors.find(i->first)==colors.end())             
        {
            stack.push(i->first);
            colors[i->first]=1;                                       //Assign it some color
            while(!stack.empty())                                     //Naive DFS algo
            {
                int root = stack.top();
                stack.pop();
                int rootColor = colors[root];
                if(edges[root].size()>0)
                {
                    for(int j: edges[root])
                    {
                        if(colors.find(j) != colors.end())           //Check color
                        {
                            if(colors[j]==rootColor)
                            return false;
                        }
                        else
                        {
                            colors[j]=rootColor==1?0:1;             //Assign the opposite color
                            stack.push(j);
                        }
                    }
                }
            }
        }
    }
    return true;                                                    //The graph is bipartite
}  


int main(){
    vector<vector<int>>temp{{1,2},{3,4},{3,5}};
    cout<<possibleBipartition(4,temp);
}