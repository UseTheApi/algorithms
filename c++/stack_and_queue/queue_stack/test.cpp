//
//  test.cpp
//  algorithms. stack and queue implementations. queue implementation from a stack
//
//  Created by alifar on 11/20/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queue_stack.hpp"
#include <iostream>

TEST_CASE("Queue Enqueue and Top"){
  QueueFromStack<int> queue;
  queue.Enqueue(5);
  REQUIRE(queue.Top() == 5);
  queue.Enqueue(10);
  REQUIRE(queue.Top() == 5);
  queue.Enqueue(15);
  REQUIRE(queue.Top() == 5);
}

TEST_CASE("Queue Dequeue and Top"){
  QueueFromStack<int> queue;
  queue.Enqueue(5);
  queue.Enqueue(10);
  queue.Enqueue(15);
  REQUIRE(queue.Top() == 5);
  queue.Dequeue();
  REQUIRE(queue.Top() == 10);
  queue.Dequeue();
  REQUIRE(queue.Top() == 15);
  queue.Dequeue();
  REQUIRE(queue.empty() == true);
}
