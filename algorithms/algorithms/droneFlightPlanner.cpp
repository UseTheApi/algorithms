//
//  droneFlightPlanner.cpp
//  algorithms
//
//  Created by alifar on 7/2/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include "droneFlightPlanner.hpp"

/*
 You are planning the amount of fuel need to complete a drone flight.
 To fly higher, the drone burns 1 liter of fuel per feet. However, flying lower charges the drone with the amount of energy equivalent to 1 liter of fuel for every feet. Flying sideways takes no energy (only flying up and down takes/charges energy).
 
 Given an array of 3D coordinates named route, find the minimal amount of fuel the drone would need to fly through this route.
 Explain and code the most efficient solution possible, with the minimal number of actions and variables.
 
 Example:
 Completing the route [{x:0, y:2, z:10}, {x:3, y:5, z:0}, {x:9, y:20, z:6}, {x:10, y:12, z:15}, {x:10, y:10, z:8}] requires a minimum of 5 liters of fuel.
 
 Solution 1:
    1. no need to review x and y coordinates because the drone only burns fuel when going up and down  - coordinate z.
    2. assume we take a list of z coordinate like: [10, 0, 6, 15, 8]
    3. we start with 0 fuel so we can build a list of distace that was made by drone. Drone starts in a point of z:10 and goes to 0, then goes up to 6 again. result list: [+10, -6, -9 (15-6), +7 (15-8)]
    4. now we can build a list of litters that we have on each coordinate having 0 on start: [0, 10, 4, -5, 2]. The minimal number is an answer: -5
 Solution 2 (too simple to seem to be right, but it works):
    1. find the most highest point in list of coordinates
    2. find a subtraction between the highest point and a point of the beginning
    3. return subtraction
*/

void printList(std::string name, std::vector<int> arr){
    std::cout << name << std::endl;
    for(auto it: arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int littersRequired(std::vector<int> coordinates){
    std::vector<int> distance(coordinates.size());
    std::vector<int> litters(coordinates.size());
    distance[0] = 0;
    litters[0] = 0;
    printList("coordinates", coordinates);
    for(int i=1; i < distance.size(); ++i){
        distance[i] = coordinates[i-1] - coordinates[i];
        litters[i] = distance[i] + litters[i-1];
    }
    printList("distance", distance);
    printList("litters", litters);
    int min_litters = *std::min_element(litters.begin(), litters.end());
    return min_litters > 0 ? min_litters : min_litters*(-1);
}

int littersRequiredSimple(std::vector<int> coordinates){
    int highest_point = *std::max_element(coordinates.begin(), coordinates.end());
    return highest_point - coordinates[0];
}