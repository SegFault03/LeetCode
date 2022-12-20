#include<bits/stdc++.h>
using namespace std;

//NOTES:
/*
This is essentially a problem of checking if a graph is connected or not. One can use either BFS or DFS to do that.
Each room can be treated as a vertex, with the keys being treated as a directed edge. So for a room[i] containing [k,l,m] where i,k,l,m are rooms,
i is a vertex and i->k,i->l,i->m are the edges.
Ultimately we need to check if the number of vertices visted after performing the search is equal to the number of vertices in the graph.
Time Complexity = O(n)
Space Complexity = O(n)
*/

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int>stack;                                //STACK FOR IMPLEMENTING DFS
    unordered_map<int,int>keys;                     //MAP FOR KEEPING TRACK OF VISITED VERTICES

    //Standard DFS Algo
    stack.push(0);
    while(!stack.empty())                           //Keep doing until the stack is empty
    {
        int t = stack.top();                        //Pop a vertex
        stack.pop();
        keys[t]=1;                                  //Mark the popped vertex as visited
        if(rooms[t].size()>0)
        {
            for(int j: rooms[t])
            {
                if(keys.find(j)==keys.end())        //Push any vertex reachable from the popped vertex that has not been visited yet
                stack.push(j);
            }
        }
    }
    return keys.size()==rooms.size()?true:false;    //Check if all vertices in the graph have been marked as visited or not
}

int main(){
    vector<vector<int>>temp{{3},{2},{2},{1},{0}};
    cout<<canVisitAllRooms(temp);
}