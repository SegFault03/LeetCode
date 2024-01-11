#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),endGene)==bank.end()) return -1;
        unordered_map<string,vector<string>>adjList;
        unordered_map<string, int>vis;
        queue<string>queue;
        for(int j=0;j<bank.size();j++)
        {
            int count = 0;
            for(int i=0;i<8;i++)
            {
                if(startGene[i]!=bank[j][i])
                    count++;
            }
            if(count==1){
            adjList[startGene].push_back(bank[j]);
            adjList[bank[j]].push_back(startGene);
            }
        }

        for(int j=0;j<bank.size();j++)
        {
            for(int k=j+1;k<bank.size();k++)
            {
                int count = 0;
                for(int i=0;i<8;i++)
                {
                    if(bank[j][i]!=bank[k][i])
                        count++;
                }
                if(count==1){
                adjList[bank[j]].push_back(bank[k]);
                adjList[bank[k]].push_back(bank[j]);
                }
            }
        }

        queue.push(startGene);
        vis[startGene] = 0;
        while(!queue.empty())
        {
            string rootGene = queue.front();
            queue.pop();
            int disFromStart = vis[rootGene];
            for(string neighbour: adjList[rootGene])
            {
                if(vis.find(neighbour)==vis.end())
                {
                    vis[neighbour] = disFromStart+1;
                    queue.push(neighbour);
                }
                else
                {
                    if(vis[neighbour]>disFromStart+1)
                    {
                        vis[neighbour] = disFromStart+1;
                        queue.push(neighbour);
                    }
                }
            }
        }
        return vis.find(endGene)==vis.end()?-1:vis[endGene];
    }



int main(){
    vector<string>bank{"AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"};
    string a = "AACCTTGG";
    string b = "AATTCCGG";
    cout<<minMutation(a,b,bank);
}