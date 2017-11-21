//
//  test.cpp
//  algorithms. stack and queue implementations. stack_queue
//
//  Created by alifar on 11/21/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack_queue.hpp"
#include <iostream>

TEST_CASE("Stack Push and Top"){
  StackFromQueue<int> stack;
  stack.Push(3);
  REQUIRE(stack.Top() == 3);
  stack.Push(5);
  REQUIRE(stack.Top() == 5);
  stack.Push(10);
  REQUIRE(stack.Top() == 10);
}

TEST_CASE("Stack Pop and Top"){
  StackFromQueue<int> stack;
  stack.Push(3);
  stack.Push(5);
  stack.Push(10);
  REQUIRE(stack.Top() == 10);
  stack.Pop();
  REQUIRE(stack.Top() == 5);
  stack.Pop();
  REQUIRE(stack.Top() == 3);
  stack.Pop();
  REQUIRE(stack.empty() == true);
}
