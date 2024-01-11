#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLN.
 * Simple greedy solution which deletes the baloon with the minimum cost of deletion when any two consecutive
 * baloons of the same colour are encountered.
 * One important point to note is that here for every two baloon of the same colour, one HAS to be deleted.
 * This means if 5 baloons of the same colour are present consecutively, 4 baloons HAVE to be deleted in any
 * case. To minimize the cost of deletion, we must delete the 4 baloons which have the minimum cost of deletion.
 * This can be easily achieved by deleting the baloon having the minimum cost, taking 2 baloons at a time.
*/
int minCost(string colors, vector<int>& neededTime) {
        int currMin = neededTime[0], cost = 0;
        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[i-1]){
                cost += min(currMin,neededTime[i]);                     //delete the baloon having a lower cost
                currMin = max(currMin,neededTime[i]);                   //update the current min value as the cost of the baloon which was not deleted
            }
            else
            currMin = neededTime[i];
        }
        return cost;
    }


int main(){
}