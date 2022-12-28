#include<bits/stdc++.h>
using namespace std;

/*
NOTES: This is less of a problem, and more of an example case of priority queue.
The approach is quite simple: Remove stones from the biggest piles first, as the 
greater an element,the greater its floor(element/2), thus maximizing the number
of stones removed => minimizing the total number of stones remaining (The objective).

It's a simple greedy strategy which, after removing stones from any element, sorts 
the entire array in descending order to find the next highest element.
However, if we implement the solution using a simple array, the following problem
will arise:
-> Repeated calls to sort the array, which would increase the time complexity. [O(knlogn)]

Instead, we can use a priority queue, which implements a max heap to automatically sort
(max heapify) the elements. Thus the maximum element will be given the greatest priority
and be popped first. We can also solve the problem of increasing complexity due to sorting 
after each remove operation as inserting an element into a max heap takes O(log n) time, 
thus the total time complexity will be O(klogn) as compared to O(knlogn) when using an array.
*/

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>pq(piles.begin(),piles.end());                   //Builds the max heap in O(n) time using Floyd's algorithm
    for(int i=1;i<=k;i++)
    {
        int temp = pq.top();                                            //Pop the maximum element
        pq.pop();
        temp-=floor(temp/2);
        pq.push(temp);                                                  //Push the modified element, takes O(log n) time
    }
    int s=0;
    while(!pq.empty())
    {
        s+=pq.top();
        pq.pop();
    }
    return s;
}

int main(){
    vector<int>test{1,1,1,1,1,1};
    cout<<minStoneSum(test,1000);
}

