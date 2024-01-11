#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
 * This is a DP problem.
 * To find the total no. of ways to, say, get a number k using n dices, we first need to find how to split
 * up k into n different components.
 * Using a human centric approach, let's consider the number of ways to get 6 using 2 dices
 * (1,5),(2,4),(3,3),(4,2),(5,1)
 * Clearly we see that if we assign 1 to one dice, and the remaining to the other, and then
 * continue this until <6, we can get all possible combinations.
 * But this is when we only have 2 dice available, what about 3?
 * Thankfully, recursion takes care of that problem. We can keep assigning one number to one dice,
 * and the remaining number to the other dice (can be >1), and recursion will then break up the
 * remaining dice to account for all possible combos.
 * Consider an example:
 * All the ways to get 6 using 3 dice
 * (1,1),(5,2) where (x,y) indicates x = number to be generated, y = dice used to generate it
 * Other possible moves are:
 * (2,1) (4,2)
 * (3,1) (3,2)
 * (4,1) (2,2)
 * Now, (5,2) can also be expanded in the same way:
 * (1,1),(4,1)
 * (2,1),(3,1)
 * (3,1),(2,1)
 * (4,1),(1,1)
 * Thus if we now consider the move (1,1),(5,2) considering the moves for (5,2), we get:
 * (1,1),(1,1),(4,1)
 * (1,1),(2,1),(3,1)
 * (1,1),(3,1),(2,1)
 * (1,1),(4,1),(1,1)
 * Thus, we can see that recursion helps us get all possible combos.
 * To convert it into a bottom up approach, we need to calculate all the possible moves for smaller numbers using 
 * a smaller number of dice.
 * We can construct a dp table of rows=1 to no.of dice and columns = 1 to max(faces,target) [since in some cases
 * faces > target]
 * We then start from no. of dice = 1 and fill up the whole table.
 * 
 * The procedure to fill up dp[i][j]:
 * dp[i][j] = 0 if j>i*faces OR j<i ------------(i)*
 *            1 if i=1 AND j<faces -------------(ii)
 *            f(i,j)----------------------------(iii)
 * where,
 * f(i,j) = from k=1 to k<j,
 *              i.  check (i)
 *              ii. sum += dp[i-1][j-k]**
 * f(i,j) = sum
 * 
 * *j>i*faces indicates the number to be generated cannot exceed no.of dice * faces, as this is impossible 
 * to generate. Like generating 18 using 2 dice. We can generate a maximum of 12 (2*6) using 2 dice having 
 * 6 faces so 18 cannot be generated.
 * j<i indicates the case 
 * **dp[i-1][j-k] indicates the number of ways in which j-k (remaining number) can be generated using i-1 (remaining
 * dice). Note that we are always dividing the dice in groups of (1, dice-1). Thus 1 dice will always generate
 * one number, the the remaining dice (dice-1) will generate the remaining number.
*/

//implements f(i,j) where dice = i, total = j
int calcNumberOfWays(int dice, int faces, int total, vector<vector<int>>&dp){
    int ways = 0;
    dice--;
    int factor = 1e9+7;
    for(int count=1;count<total;count++){
        if(total-count < dice || count > faces)                         //(i)
        break;
        ways += dp[dice-1][total-count-1];
        ways = ways%factor;
    }
    return ways;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>>dp(n,vector<int>(max(k,target),0));
    for(int i=0;i<k;i++)                                                //(ii)
    dp[0][i] = 1;  
    for(int i=1;i<n;i++){
        for(int j=0;j<target;j++){
            if(j<i)                                                     //(i)
            continue;
            else if(j+1>(i+1)*k)                                        //(i) [the second condition]
            break;
            else
            dp[i][j] = calcNumberOfWays(i+1,k,j+1,dp);                  //(iii)
        }
    }
    return dp[n-1][target-1];      
}

int main(){
    int n = 30, k = 30, target = 500;
    cout<<numRollsToTarget(n,k,target);
}