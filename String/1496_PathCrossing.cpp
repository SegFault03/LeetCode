#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOL
bool isPathCrossing(string path) {
        unordered_set<string>coordStore;
        coordStore.insert("0,0");
        pair<int,int> coord = {0,0};
        for(int i=0;i<path.length();i++){
           if(path[i]=='N')
           coord.second++;
           else if(path[i]=='E')
           coord.first--;
           else if(path[i]=='S')
           coord.second--;
           else
           coord.first++;
           string coordString = to_string(coord.first)+","+to_string(coord.second);
           if(
               coordStore.find(coordString)!=coordStore.end()
            )
           return true;
           else
           coordStore.insert(coordString);
        }
        return false;
    }


int main(){
    string test = "ENNNNNNNNNNNEEEEEEEEEESSSSSSSSSS";
    cout<<isPathCrossing(test);
}