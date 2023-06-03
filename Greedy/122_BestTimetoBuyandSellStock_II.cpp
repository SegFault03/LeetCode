/*
This problem comes after ..\Sliding Window\121_BestTimetoBuyandSellStock.cpp

Using a GREEDY APPROACH

The main difference between this and the previous (121) is that in the earlier solution,
we are allowed to buy and sell a stock only once, while this time, we are allowed to buy and sell a stock
multiple times, with the only constraint being the fact that we are permitted to hold only one stock at
any given time. 
This means that we cannot have a sliding window in this case, as that will only allow us to find
the max profit of a SINGLE transaction, whereas now we want to find out the total profit generated from
multiple transactions.

Intuition and Approach:
Since the objective is to maximize our total profit, we adopt the following strategy:
(i) Buy a stock at day 'i', say stock price at day 'i' = cp
(ii) At day j, j>i, check if price(j) - cp > 0 or not
    a. if true, sell the stock immediately (as there is a profit), add the profit generated
    to total profit, and then rebuy the stock immediately [cp = price(j)] (Why? see below)
    b. Else, we reinitialize cp = price(j), as this condition implies that the stock has fallen,
    and any subsequent rise, will yield greater result than it would have for the previous cp
    (This is the same logic we used in 121). So we buy the stock at a lower price instead.
(iii) Continue step (ii) for j=1 until j = price.size()

The idea here is to maximize our profits by MAXIMIZING THE NUMBER OF TRANSACTIONS (BUYING AND SELLING
OF STOCKS). In other words, we generate small profits off each transactions, in hopes that the total
profit will be maximum, in true greedy fashion (maximizing local optimums to maximize the global optimum).
Also, note how we NEVER hold the stocks.

Now, to prove that it will indeed result in maximum profits in all possible cases, consider two possible
cases:
Case-(i) price = [1,2,3,5,6]
i=0: cp = 1
i=1: 2-1 > 0 -> total profit = 1, cp = 2 (buy the stock again)
i=2: 3-2 > 0 -> total profit = 1 + 1 = 2, cp = 3
i=3: 5-3 > 0 -> total profit = 2 + 2 = 4, cp = 5
...and so on. Ultimately, total profit = 5

Note in this case, if we plot a line graph, the stock price only grows up. Despite that, we do not hold
the stock. Why? Because the profit we would get on holding it is the same as selling it and buying it repeatedly!
If we held the stock, profit = 6 - 1 = 5, the same as buying and selling it repeatedly.
This can be proven mathematically -> [x, x+1, x+3]. (x+3)-(x+1) = ((x+1) - (x))+((x+3)-(x+1)) = 3
Note this will only hold true IF THE STOCK IS STRICTLY INCREASING.

Case-(ii) price = [3,5,4,7] (Note here the stock is not strictly increasing)
i=0: cp = 3
i=1: 5-3 > 0 -> total profit = 2, cp = 5
i=2: 4-5 < 0 -> cp = 4
i=3: 7-4 > 0 -> total profit = 2 + 3 = 5
Now, let's see what would've happened if we bought the stock at cp = 3 and held it until price = 7.
Total profit would be = 7 - 3 = 4. But we see that maximum profit would've been 5 if we bought and sold it 
immediately. Why? Bcuz when we hold a stock, and the stock is not strictly increasing, profit is measured
between the sp and cp. Even if the stock plunged somewhere in between and then rose back up, as in this case.
But if we sell the stock immediately after it rises, and then buy it again when it is dipping, our profit
is calculated as sp - cp (during the dip), which actually maximizes our profit.
ACCEPTED SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int s=0, cp=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-prices[cp]>0)
            {
                s+=prices[i]-prices[cp];
                cp = i;
            }
            else
            cp = i;
        }
        return s;
    }

int main(){
}