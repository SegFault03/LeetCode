#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
/*
NOTE: I am A in this game.

Essentially the main logic here is to find out who has a greater no. of turns.
The one who can keep removing As or Bs will win. Thus we will have to find out how many such 
As or Bs can be removed. The order in which A/B are removed or their selection does not
affect the winner, as it doesn't matter if I'm removing the second A in ...AAAA... or the third.
At the end of the day, I can only play 2 rounds (as there are 2 As that I can remove). Also, 
the rules have been made in such a way that there will never be an opportunity where the number of
As that I can remove might be greater than the number of As I could remove at the begining. Why?
Consider the case AB..[contains a string of Bs]..A..[contains a string of Bs]..BA. 
The only way this can be reduced is: ABABA. No matter how many or which Bs are removed ABBA will 
always be the end result. Thus no chance of getting one more A because of Bs action. Similarly,
there is no choice or selection that A can make that can increase the number of As that can be
deleted in the future. (I've already explained that it doesn't matter which A i choose to delete
or the order in which i delete, the end result will always be the same).

This means that the only way to win the game is to maximize my number of turns -> A greedy choice.
I delete one A in every turn I get, and hope that the number of As that I can delete is more than
the number of Bs that B can delete.
If we have the same number of As and Bs, I will lose as I will run out of As before B runs out of B
(exactly one round before to be exact).
I will also lose if B has higher number of Bs than I have As to delete.
In a way the winner is determined even before the game has begun.
*/
bool winnerOfGame(string colors) {
        if(colors.size()<3) return false;
        int turnsForA = 0, turnsForB = 0, count = 1;
        char flag = colors[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==flag)
            count++;
            else{
                if(count>=3)                                //must be at least 3 consecutive As or Bs to have any A or B that can be deleted
                {
                    if(flag=='A')
                    turnsForA += (count-2);                 //Number of As or Bs that can be deleted = Number of triplets of A/B that can be made
                    else                                    //For 4 As: AAAA = 2 triplets, AAAAA = 3 triplets.....n As = n-3+1 = n-2
                    turnsForB += (count-2);
                }
                flag = colors[i];
                count = 1;
            }
        }
        if(count>=3){
            if(flag=='A')
            turnsForA += (count-2);
            else
            turnsForB += (count-2);
        }
        return turnsForA>turnsForB;
    }

int main(){
}