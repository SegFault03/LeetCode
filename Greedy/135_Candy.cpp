#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
//ACCEPTED SOLUTION
int candy(vector<int>& ratings) {
        int s = ratings.size(), i, sum = 0;
        //assign one candy to each child as this is the minimum they must have
        vector<int>candies(s,1);
        //now, make sure that every child that is ranked higher than their LEFT neighbour
        //has at least one more candy than their LEFT neighbour
        for(i=1;i<s;i++)
        {
            if(ratings[i]>ratings[i-1])
            candies[i] = candies[i-1]+1;
        }
        /*
        But this alone doesn't solve the problem. We've made sure that every child that has a higher rating
        than their left neighbour will have more candies than their left neighbour, but what about their right
        neighbour? We havent't considered that case yet.

        For eg:
        Initially, 
        ratings: [2,3,1,5,4,2]
        candies: [1,1,1,1,1,1]

        After first pass (left-to-right)
        candies: [1,2,1,2,1,1] (See that all children who have a higher rating than left neighbours have more candies)
        But Consider rating[4] = 4 -> 4>2 but has the same number of candies than 2.
        The same goes for rating[3] = 5>4
        */
       //So now we check if every child that has a higher rating than their RIGHT neighbour has more candies
       //than their RIGHT neighbour: To do that we start from the end of the array
        for(i=s-2;i>=0;i--)
        {   
            //IF i has more candies than i+1 already, then there's no need to distribute more candy
            //ELSE i must have AT LEAST one more candy than i+1
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1])
            candies[i] = candies[i+1]+1;
        }
        for(i=0;i<s;i++)
        sum += candies[i];
        return sum;
    }


int main(){
}