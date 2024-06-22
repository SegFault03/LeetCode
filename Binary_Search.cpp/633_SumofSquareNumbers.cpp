#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
#include "../Headers/Trie.h"
using namespace std;
/**
 * ACCEPTED SOLUTION
*/
bool judgeSquareSum(int c) {
        long long int a=0, lb, ub, mid;
        while(a<=floor(sqrt(c))){
            // cout<<"a = "<<a<<endl;
            lb = a;
            ub = floor(sqrt(c));
            while(ub>=lb){
                mid = (ub-lb)/2 + lb;
                // cout<<"lb = "<<lb<<",ub = "<<ub<<", mid = "<<mid<<endl;
                if(a*a + mid*mid == c)
                return true;
                else if(a*a + mid*mid > c)
                ub = mid - 1;
                else
                lb = mid + 1;
            }
            a++;
        }
        return false;
    }


int main(){
}