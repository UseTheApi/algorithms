//
//  multiply_number.cpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "multiply_number.hpp"

/*
 There is a card and at the beginning there is a number s on it, in each step you can do one of this operation:
	Suppose the number on this card is x, change it into 2x+1.
	Suppose the number on this card is x, change it into 3x+1.
 Please compute and return the minimal number of operations to change the number of your card into t. If that is impossible, return -1.
*/

MultiplyXPlusOne::MultiplyXPlusOne(){
    min_steps_number = 0;
}

int MultiplyXPlusOne::square_step(int num){
    return (num - 1)/2;
}

int MultiplyXPlusOne::cubical_step(int num){
    return (num - 1)/3;
}

int MultiplyXPlusOne::module_square(int num){
    return (num - 1)%2;
}

int MultiplyXPlusOne::module_cubical(int num){
    return (num - 1)%3;
}

int MultiplyXPlusOne::perform_square_step(int &result){
    steps.push(square_step(result));
    ++min_steps_number;
    return steps.top();
}

int MultiplyXPlusOne::perform_cubical_step(int &result){
    steps.push(cubical_step(result));
    ++min_steps_number;
    return steps.top();
}

int MultiplyXPlusOne::MinimalSteps(int start, int result){
    /*
     Doesn't work with input 4;22 or with any input when it is impossible to step to second number
    */
    if(result < start){
        return -1;
    }
    if(module_square(result) && module_cubical(result)){
        return -1;
    }
    bool cubical = false;
    bool square = false;
    while(result != start){
        if(!module_cubical(result)){
            result = perform_cubical_step(result);
            cubical = true;
            square = false;
        } else if(!module_square(result)){
            result = perform_square_step(result);
            square = true;
            cubical = false;
        } else{
            steps.pop();
            --min_steps_number;
            result = steps.top();
            if(cubical){
                result = perform_square_step(result);
                square = true;
                cubical = false;
            } else{
                result = perform_cubical_step(result);
                cubical = true;
                square = false;
            }
        }
    }
//    std::cout << min_steps_number << std::endl;
    return min_steps_number;
}