//
//  main.cpp
//  drone_flight_planner
//
//  Created by alifar on 10/10/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "drone_flight_planner.hpp"
#include <vector>
#include <iostream>

using namespace std;


// TEST: Drone Flight Planning. both solutions: droneFlightPlanner.hpp
//    std::vector<int> coordinates {10, 0, 6, 15, 8};
//    std::cout << littersRequired(coordinates) << std::endl;
//    std::cout << littersRequiredSimple(coordinates) << std::endl;

int main(int argc, const char *argv[]){
	vector<int> coordinates;
	int item;

	cout << "Please enter items: ";
	do{
		cin >> item;
		coordinates.push_back(item);
	} while(cin.get() != '\n');

	cout << "Litters Required: " << LittersRequired(coordinates) << endl;
	cout << "Litters Required Simple: " << LittersRequiredSimple(coordinates) << endl;

	return 0;
}