//
//  maxProfitInStock.cpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "maxProfitInStock.hpp"
#include <algorithm>
/*
 
 Suppose we could access yesterday's stock prices as a list, where:
 
 The indices are the time in minutes past trade opening time, which was 9:30am local time.
 The values are the price in dollars of Apple stock at that time.
 So if the stock cost $500 at 10:30am, stock_prices_yesterday[60] = 500.
 
 Write an efficient function that takes stock_prices_yesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.
 
 Ex: stock_prices_yesterday = [10, 7, 5, 8, 11, 9], then you'd buy for $5 and sell for $11 => answer is 6
 
 Solution:
    1. keep track of max_profit (start with 0)
    2. keep track of min_price (start from input[0])
    3. return max_profit after iteration through array
 */


int maxStockProfit(std::vector<int> &stock_prices){
    int max_profit = 0;
    int min_price = stock_prices[0];
    for(int i = 0; i < stock_prices.size(); ++i){
        min_price = std::min(min_price, stock_prices[i]);
        max_profit = std::max(max_profit, stock_prices[i] - min_price);
    }
    return max_profit;
}
