#include<bits/stdc++.h>
#include "../Headers/ListNode.h"
#include "../Headers/tree.h"
#include "../Headers/VectorParser.h"
using namespace std;

//ACCEPTED SOLUTION

vector<int> sequentialDigits(int low, int high) {
        int a = to_string(low).length(), b = to_string(high).length();
        vector<int> ans;
        
        //Generate all possible integers which fit the criteria (4 digit numbers, 5 digit numbers,..)
        for (int i = a; i <= b; i++) {
            string x = "0";
            int begin = 1;
            
            //First make sure that the generated number is >= low
            //Also, the first digit in the number should be such that the succeeding digits
            //should not be greater than 9. For e.g, for a 4 digit number, the first digit  cannot be
            //greater than 6, for if it was 7, the number 78910 would be generated
            while (stoi(x) < low && begin <= (10 - i)) {
                x = to_string(begin);
                for (int k = 1; k < i; k++)
                    x += to_string((x[k - 1] - 48) + 1);
                begin++;
            }
            
            //Check if the generated number falls in the range
            if (stoi(x) >= low && stoi(x) <= high)
                ans.push_back(stoi(x));
            
            //if not, we've exhausted all possible numbers using this many digits (4 digit, 5-digit, etc.)
            //Move to the next higher digit space
            else
                continue;
            
            //Continue generating digits as long as the first digit is <= 10-i
            while (begin <= (10 - i)) {
                x = to_string(begin);
                for (int k = 1; k < i; k++)
                    x += to_string((x[k - 1] - 48) + 1);
                
                //No more digits can be generated, return    
                if (stoi(x) > high)
                    return ans;
                else
                    ans.push_back(stoi(x));
                begin++;
            }
        }
        return ans;
    }


int main(){
    int l = 100,
    h = 300;
    VectorParser::printOneDArray(sequentialDigits(l, h));
}