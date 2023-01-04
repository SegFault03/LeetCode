#include<bits/stdc++.h>
using namespace std;
/*
NOTES:
This is essentially a math problem.
Obviously, in order to minimize the number of rounds required, we would like to make as many groups of 3 possible, since 
we'll be able to do more tasks in lesser rounds in that way.
Thus every count can be represented as = 3k, 3k+1 and 3k+2
Count                   Number of rounds required:
------------------------------------------------------------
3k                                  k
------------------------------------------------------------
3k+1                    can't be k since the remaining 1 task 
                        cannot be completed in either 2 or 3 
                        rounds. But (3k+1)-{3(k-1)+1} = 3
                        In other words, for some number n,
                        n=3k+1=3(k-1)+1+3=3(k-1)+2*2
                        This means number of rounds required
                        =(k-1)+2=k+1
-------------------------------------------------------------
3k+2                    Can be easily broken down into k + 1 
                        round
--------------------------------------------------------------
*/
int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>count;
        for(int i: tasks)
        count[i]++;
        int rounds=0;
        for(auto [task,value]:count)        //task=key, value=count
        {
            if(value==1)
            return -1;
            if(value%3==0)
            rounds+=value/3;
            else if(value%3==1)
            rounds+=((value-4)/3+2);
            else
            rounds+=(value/3+1);
        }
        return rounds;
    }

int main(){
    vector<int>test{2,2,3,3,3,4,4,5,5,5,5};
    cout<<minimumRounds(test);
}