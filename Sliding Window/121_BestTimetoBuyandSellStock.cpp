/*
Sliding window technique demo
The objective here is to maximize profits. Meaning obj: max(selling price - buying price)

Algorithm:
Inititally, consider the first day as the day the stock is bought. Thus cp = price(0)
As we iterate through the array,
If price(i) - cp < 0, this indicates that price(i)<cp
    At this point we no longer need to consider the current cp. As even if for some j, where j>i,
    price(j) - cp > 0, price(j) - price(i) will still be greater than price(j) - cp > 0, since
    price(i)<cp.
    E.g, consider price = [7,5,10]
    i=0, Initially, cp = price(0) = 7
    i=1, 5 - 7 = -2 -> -2 < 0
    i=2, 10 - 7 = 3 -> 3 > 0
    But it makes no sense to keep considering cp = 7 as if we consider 5 as cp,
    then 10 - 5 = 5 -> 5 > (10 - 7), thus helping us maximize profits. Thus, it is better to consider
    5 as the new cp, as any element after 7 that is lesser than it will obv yield greater profits than
    7 itself.
    Thus, if for any i, i>0, if  price(i) - cp < 0, then cp = price(i) 
    This guarantees that any subsequent elements, if larger than previous cp will yield greater profits.
    Another way of thinking is that we always want to buy at the lowest possible cost, so we always try 
    finding the lowest possible cost.
    Else, if price(i) - cp > 0, we compare it with maxProfit, and update accordingly, making no change to cp
    this time.
    In other words, we try finding i for which price(i) is largest where i > j for cp = price(j) 

    Consider a scenario: price: [7,6,5,10,2,3]
    i=0, cp = 7
    i=1, 6-7 = -1 -> cp = 6
    i=2, 5-6 = -1 -> cp = 5
    i=3, 10-5 = 5 -> maxProfit = 4 (Note how profit would be less if we kept 7 or 6 as cp)
    i=4, 2-6 = -4 -> cp = 2
    i=5, 3-2 = 1 -> maxProfit = 5 > 1 thus maxProfit not updated
    Thus ans = 5.
    ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int start = 0, maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-prices[start]<0)
            start = i;
            else
            maxProfit = prices[i]-prices[start]>maxProfit?prices[i]-prices[start]   :maxProfit;
        }
        return maxProfit;
    }

int main(){
    vector<int>test{7,6,5,10,2,3};
    cout<<maxProfit(test);
}