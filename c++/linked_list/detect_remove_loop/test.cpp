//
//  test.cpp
//  algorithms. Linked List. detect and remove a cycle
//
//  Created by alifar on 11/23/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "detect_remove_loop.hpp"
#include <iostream>
#include <vector>

LinkedList<int> * create_list(const std::vector<int> &items){
  LinkedList<int> *list = new LinkedList<int>();
  for(auto it: items){
    list->append(it);
  }
  return list;
}

void add_cycle(LinkedList<int> *list, int cycle_node_value){
  LinkedList<int> *cycle_node = list->get_node(cycle_node_value);
  LinkedList<int> *last = list->get_last();
  last->set_next(cycle_node);
}

TEST_CASE("Detect And Remove cycle. Detect cycle"){
  std::vector<int> items{5, 4, 3, 6, 1, 9};
  int cycle_node_value = 3;
  LinkedList<int> *list = create_list(items);
  REQUIRE(detect_loop(*list) == false);
  add_cycle(list, cycle_node_value);
  REQUIRE(detect_loop(*list) == true);
}

TEST_CASE("Detect and Remove cycle. Remove cycle"){
  std::vector<int> items{5, 4, 3, 6, 1, 9};
  int cycle_node_value = 3;
  LinkedList<int> *list = create_list(items);
  add_cycle(list, cycle_node_value);
  detect_and_remove_loop(*list);
  delete list; // will fail if loop is not removed
  list = new LinkedList<int>();
  // empty list
  detect_and_remove_loop(*list);
  delete list;
  // single node list
  list = new LinkedList<int>();
  list->push(4);
  add_cycle(list, 4);
  detect_and_remove_loop(*list);
  delete list;
}
