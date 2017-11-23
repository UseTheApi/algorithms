# Detect and Remove cycle from Linked List

#### Task
Given a list with a loop:
```
5->4->3->6->1->9
         |_____|
```
Write a function to detect and remove the loop. Use Linked List implemented [**here**](/c++/linked_list/implementation).

#### Notes
**Tip**: list is singly linked (loop can go only from the last node).

###### Cycle detection
There are multiple solutions: the most effective is to go with slow and fast pointer until they meet each other. slow step indicates taking ```next()``` from current step and fast step indicate taking ```next()->next()``` from current step.

###### Cycle removal
Removing is based on calculating a length of the loop and moving from the head to start of the loop. Calculating a length can be done by incrementing a flag, or by moving a **head pointer**.
