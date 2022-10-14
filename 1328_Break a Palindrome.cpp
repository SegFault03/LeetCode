#include<bits/stdc++.h>
using namespace std;
//SOLUTION: https://leetcode.com/problems/break-a-palindrome/submissions/819598128/
class Solution {
public:
    string breakPalindrome(string palindrome) {
       if(palindrome.length()==1)
       {
           return "";
       }
       int l = palindrome.length();
       int p = l-1;
       for(int i=0;i<(l/2);i++)
       {
           if(palindrome[i]>'a'&&palindrome[i]<='z')
            {
                p = i;
                break;
            }
       }
       palindrome[p]=p==l-1?'b':'a';
       return palindrome;
    }
};

//NOTES:
/*
Uses Greedy strategy.
Time complexity: Theta(n/2)
Lexigraphically smallest is the key word in this problem.
Meaning for a palindrome: baacaab, the possible solutions are: caacaab, bbacaab, baacaaa, aaacaab
But in these, aaacaab is lexicographically smallest.
This means for any possible permutation, a word in which the 'a' or 'a'(s) come first will always be
the lexicographically smallest among all possible permutations, since it is not possible to go any lower.
Thus, the strategy to is to produce a non-palindrome word where all the a's come first and the non-a's come last.

ALGORITHM:
We are not interested in scanning all of the string, but only its first half, that is because all valid test 
cases will always be a palindrome, so s[i]=s[l-i-1] always, no need to check it. l = s.length()

The objective is to generate a non-palindrome where the a or a's come first.
Thus the greedy strategy would be to set the first non-a character found in the given word to a.
If however, no non-a characters are found, then set the last character of string to b. Since a non-a character
must always come last to be lexicographically smallest, and since we've found no 'a's in the first half of the string
, that implies the entire string (except possibly the middle character, if l is odd) are full of a's. That is because
all strings will always be palindrome, so if the first half only consists of 'a's, the second half must also only consist
of only 'a's.

set flag = l-1
for i=0 to l/2-1:
    Check if s[i] is greater than 'a'
        if true, store 'i' in flag, break       //First non-a character encountered.

check if flag = l-1
    if true, set s[flag]='b'        //Entire string consists of a's
    else, set s[flag]='a'           
return s
*/