#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * The idea is to play the tokens which have the least cost, keep doing it until we
 * run out of power, and once we run out, sell the token with the max power. Then go
 * back to playing tokens with the least cost.
*/
int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n==0) return 0;
        sort(tokens.begin(), tokens.end());
        //fast return;
        if(tokens[0]>power) return 0;
        int lp = 0, rp = n-1, maxS = 0, score = 0;
        while(rp>=lp){
            if(tokens[lp]<=power){
                score++;
                power-=tokens[lp];
                lp++;
                maxS = max(maxS, score);
            }
            else{
                if(score>0){
                    power+=tokens[rp];
                    rp--;
                    score--;
                }
                else
                break;
            }
        }
        return maxS;
    }


int main(){
}