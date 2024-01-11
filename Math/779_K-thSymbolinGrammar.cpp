#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;
/**
 * It is important to figure out the pattern behind the problem first.
 * Try generating rows upto n=5. It will be seen that there is a repeating pattern.
 * Two things need to be observed:
 * i. The bit in the k'th position will be constant for any row i where 0<=i<=n. In other words if we know what bit is
 *    there at k, it will be same in all the rows, regardless of n.
 * ii. Bit at k-th position in n'th row = Bit at 2*k th position in n+1'th row. Also
 *     Bit at k-th position in n'th row = Complement of bit at 2*k-1 th position in the n+1'th row.
 * [NOTE: here k is 1-indexed]
 * From the above two observations, we can conclude that if we want to find the bit at the k'th position of n'th row, we need to find 
 * bit at k/2+1 (if odd) or k/2 (if even) position of n-1 th row.
 * Thus the recursive eqn. is as:
 *  F(n,k) =  0 if k=1
 *            1 if k=2
 *            Complement of F(n,k/2) if k>1 and is even
 *            F(n,(k+1)/2) if k>1 and is odd  
*/
int kthGrammar(int n, int k) {
        if(k==1) return 0;
        if(k==2) return 1;
        if(k%2==0)
        return kthGrammar(n,k/2)==0?1:0;
        else
        return kthGrammar(n, (k+1)/2);
    }


int main(){
}