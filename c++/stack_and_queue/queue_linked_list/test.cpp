//
//  test.cpp
//  algorithms. stack and queue implementations. queue_linked_list
//
//  Created by alifar on 11/20/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "queue_linked_list.hpp"
#include <iostream>

TEST_CASE("Queue enqueue and top"){
  Queue<int> queue;
  queue.Enqueue(5);
  queue.Enqueue(6);
  REQUIRE(queue.Top()->get_data() == 5);
  queue.Enqueue(1);
  queue.Enqueue(7);
  REQUIRE(queue.Top()->get_data() == 5);
}

TEST_CASE("Queue dequeue and top"){
  Queue<int> queue;
  queue.Enqueue(5);
  queue.Enqueue(6);
  queue.Enqueue(1);
  queue.Enqueue(7);
  REQUIRE(queue.Top()->get_data() == 5);
  queue.Dequeue();
  REQUIRE(queue.Top()->get_data() == 6);
  queue.Dequeue();
  REQUIRE(queue.Top()->get_data() == 1);
  queue.Dequeue();
  REQUIRE(queue.Top()->get_data() == 7);
  queue.Dequeue();
  REQUIRE(queue.empty() == true);
}
