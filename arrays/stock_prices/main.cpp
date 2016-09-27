//
//  main.cpp
//  stock_prices
//
//  Created by alifar on 9/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>
#include "max_profit_in_stock.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	vector<int> prices;
	int item;
	cout << "Enter stock prices (integers): ";
	do{
		cin >> item;
		prices.push_back(item);
	} while(cin.get() != '\n');
	cout << "Max profit from given prices is: " << MaxStockProfit(prices) << endl;
}

// TEST: Max Stock Profit: maxProfitInStock.hpp
//    std::vector<int> prices = {10, 7, 11, 5, 8, 9};
//    std::cout << maxStockProfit(prices) << std::endl;
