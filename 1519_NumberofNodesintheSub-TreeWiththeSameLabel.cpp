#include<bits/stdc++.h>
using namespace std;

/*
NOTES:
The logic is quite simple: Every node returns a dictionary containing a count of all the labels of its subtree
The parent node then uses that dictionary to update its own label count, updates its own subtree dictionary
and then returns it back to its ancestor. 
*/

unordered_map<char,int> countLabels(int child, int parent,unordered_map<int,vector<int>> &adjList, string &labels, vector<int> &ans)
    {
        unordered_map<char,int>labelMap;
        labelMap[labels[child]]++;
        unordered_map<char,int>tempMap;
        for(auto edge: adjList[child])
        {
            if(parent!=edge)
            tempMap=countLabels(edge,child,adjList,labels, ans);
            for(auto i = tempMap.begin();i!=tempMap.end();i++)
            labelMap[i->first]+=i->second;
        }
        ans[child] = labelMap[labels[child]];
        return labelMap;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adjList;
        vector<int>ans(n,0);
        for(auto i: edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        unordered_map<char,int>temp(countLabels(0,0,adjList,labels,ans));
        return ans;
    }

int main(){
}