//
//  factorial_fibonacci.cpp
//  algorithms
//
//  Created by alifar on 6/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "factorial_fibonacci.hpp"

/* This file contains non-recursive implementations of tasks:
   Fibonacci number and Factorial number */

long fibonacci(int n){
    long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<n+1; ++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

long factorial(int n){
    long fac[n+1];
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2; i<n+1; ++i){
        fac[i] = i*fac[i-1];
    }
    return fac[n];
}
