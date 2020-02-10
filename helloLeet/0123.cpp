//Best time to buy and sell stock 3 (dp, and an amazing solution)

/*
	The key of this idea is to consider profit_first as a discount or a coupon for the second transaction.
	For example, we have $0 at the initial state (before the first transaction), after the first transaction, we earn no money but a coupon, which can be used to buy the second stock.
	So, we use 4 vars to represent the states:
	lowest_price_first: At this state, we still try to do our first transaction, lowest_price_first means the lowest price we can buy the stock in the first transaction
	profit_first: At this state, we try to sell the stock we have (doing out first transaction), profib_first means the value of the coupon we get by sell the first stock we bought
	lowest_price_second: the price to buy second stock is really tricky, we already have a coupon, which valued profit_first, instead of nothing as we buy the first stock, so the price of the second price will be n - profit_first! At this state, we are tring to find the lowest price to buy the second stock
	final_price: At this state, we try to find a time to sell our stock and get the real money, so the profit we can get from the second transaction is exactly our final profit from these two transactions. 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price_first = INT_MAX, profit_first = 0, lowest_price_second = INT_MAX, profit_final = 0;
        for (int n : prices) {
            lowest_price_first = min(lowest_price_first, n);
            profit_first = max(profit_first, n - lowest_price_first);
            lowest_price_second = min(lowest_price_second, n - profit_first);
            profit_final = max(profit_final, n - lowest_price_second);
        }
        return profit_final;
    }
};

/the dp solution is not that difficult, we'll back in the future (maybe)
