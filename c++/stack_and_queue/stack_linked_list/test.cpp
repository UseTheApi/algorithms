//
//  test.cpp
//  algorithms. stack and queue implementations. stack_linked_list
//
//  Created by alifar on 11/21/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack_linked_list.hpp"
#include <iostream>

TEST_CASE("Stack Push and Top"){
  Stack<int> stack;
  stack.Push(5);
  REQUIRE(stack.Top()->get_data() == 5);
  stack.Push(3);
  REQUIRE(stack.Top()->get_data() == 3);
  stack.Push(7);
  REQUIRE(stack.Top()->get_data() == 7);
}

TEST_CASE("Stack Pop and Top"){
  Stack<int> stack;
  stack.Push(5);
  stack.Pop();
  REQUIRE(stack.empty() == true);
  stack.Push(5);
  stack.Push(4);
  stack.Push(1);
  REQUIRE(stack.Top()->get_data() == 1);
  stack.Pop();
  REQUIRE(stack.Top()->get_data() == 4);
  stack.Pop();
  REQUIRE(stack.Top()->get_data() == 5);
  stack.Pop();
  REQUIRE(stack.empty() == true);
}
