#include<bits/stdc++.h>
using namespace std;
/*
NOTES:
This can be treated as a graph problem and hence solved using DFS
Every character in s1 and s2 can be considered as a node in the graph and the correspoding equivalence
relation between the two characters can be considered as an edge. 

Consider an example:
s1 = "abcda" s2="afebr"
The following graphs can be generated from s1 and s2:
[a] -> [a,r]
[b] -> [f,d]
[c] -> [e]
[r] -> [a]
[f] -> [b,d]
[e] -> [c]

In other words:
Graph               Nodes           Smallest character
 G1                 [a,r]                   a
 G2                 [b,f,d]                 b
 G3                 [e,c]                   c

Now, since the objective is to find the lexicographically smallest string possible, we need to find out the 
smallest character in each of the disconnected graphs. This can be easilty done by performing a Depth-first
search and updating the smallest character as required. Hence, for each character in baseStr, we can perform
a DFS of the graph of which the character is a node of, and replace it with the minimum character of that
graph.

*/
char getReplacement(char ch, unordered_map<char,vector<char>> &adjList)
{
    if(ch==97)                                                      //if char is 'a', return as no smaller char can be found
    return ch;
    stack<char>stack;
    unordered_map<char,int>vis;
    stack.push(ch);
    char reqch;
    int minchar = ch;
    while(!stack.empty())
    {
        char parent = stack.top();
        stack.pop();
        vis[parent]=1;
        if(parent==97)
        return parent;
        if(parent < minchar)
        minchar = parent;
        for(auto edge : adjList[parent])
        {
            if(vis.find(edge)==vis.end())
            stack.push(edge);
        }
    }
    return char(minchar);
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char,vector<char>>adjList;
        for(int i=0;i<n;i++)
        {
            adjList[s1[i]].push_back(s2[i]);
            adjList[s2[i]].push_back(s1[i]);
        }
        string ans;
        for(int i=0;i<baseStr.length();i++)                         //perform a DFS for each char and replace it with the smallest char
        ans+=getReplacement(baseStr[i],adjList);
        return ans;
}

int main(){
}