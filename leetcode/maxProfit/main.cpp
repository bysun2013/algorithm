/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1)
            return 0;
        int i = 1, profit = 0, start = 0;
        while(i < size){
            while(prices[i] >= prices[i-1] && i < size)
                i++;
            profit += (prices[i-1] - prices[start]);
            while(prices[i] <= prices[i-1] && i < size)
                i++;
            start = i-1;
        }

        return profit;
    }
};

int main()
{
    int a[] = {10};
    Solution s;
    vector<int> prices(a, a+1);
    s.maxProfit(prices);

    cout << "Hello world!" << endl;
    return 0;
}
