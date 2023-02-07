#include<bits/stdc++.h>
using namespace std;

/*# Intuition
The problem can be boiled down to: Find the longest continuous subarray containing two distinct elements.

# Approach
Can be solved using a sliding window approach whose length is dynamic. We keep a memory store (a vector, for example) which contains the 
two distinct elements. We also keep a flag variable which tracks the position where an element change took place. We also use a variable 
called fruitCount to count the number of fruits in each window. The flag variable will help us change the length of the sliding window
by keeping track of the index from which the window starts. This is because every time a new window needs to be created, it must
begin from the index where the last fruit type change took place, and thus storing that index is essential.

For example, consider: [1,2,2,1,2,2,2,2,3,2,3,3,3,2,1]
Three windows in this array: 
[1,2,2,1,2,2,2,2] (0-7)
[2,2,2,2,3,2,3,3,3,2] (4-13)
[2,1] (13-14)

# Algorithm:
1. We visit each index of the array
2. We check if the memory is store is empty. (This will happen only once, at the begining) In that case we update the vector with the 
fruit type and increment fruitCount by 1.
3. We check if vector size is 1 and the current fruit does not match with the fruit type present in the array. (This will happen only once, 
at the begining) In that case we update the vector with the new fruit type and increment fruitCount by 1.
4. We check if vector size is 2 and if the current fruit matches with any of the two fruits present in the array. 
5. IF true, we increment fruitCount by 1.
6. ELSE we update the array's first index with the fruit type present at the position where the last fruit type change took place. The 
array's second index is updated with the new fruit type. Check if fruitCount is greater than max and update accordingly. 
New fruitCount = (index - flag) +1. 
7. For every index we check if the current fruit type matches with the fruit type at fruits[flag]. If false, update flag = index

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)
*/

int totalFruit(vector<int>& fruits) {
        vector<int>type;
        int ans = -99999;
        int fruitCount = 0;
        int flag = 0;
        for(int i=0;i<fruits.size();i++)
        {
            if(type.size()==0)
            {
                type.push_back(fruits[i]);
                fruitCount++;
            }
            else if(type.size()==1 && type[0]!=fruits[i])
            {
                type.push_back(fruits[i]);
                fruitCount++;
            }
            else if(type.size()==1 && type[0]==fruits[i])
            fruitCount++;
            else if(type.size()==2 && (type[0]==fruits[i] ||type[1]==fruits[i]))
            fruitCount++;
            else
            {
                type[0] = fruits[flag];
                type[1] = fruits[i];
                ans = ans<fruitCount?fruitCount:ans;
                fruitCount = (i-flag);
                fruitCount++;
                flag = i;
            }
           flag = fruits[i]==fruits[flag]?flag:i;
        }
        ans = ans<fruitCount?fruitCount:ans;
        return ans; 
    }

int main(){
    vector<int>test{1,2,1};
    cout<<totalFruit(test);
}