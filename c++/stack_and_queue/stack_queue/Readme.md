# Stack from Queue

#### Task
Implement a Stack data structure using standard implementation of queue.

#### Notes
Stack data structure may be implemented with 2 queues. When implementing Stack through Queue there is a tradeoff. We only can make 1 of Stack operations effective - ```Push``` or ```Pop```.

When having expensive ```Push``` method - we ```enqueue()``` an item to 1 queue and then ```dequeue()``` all values from the second queue into the first one. Then swap queues. This makes sure that relevant top stays always in front of the first queue. ```Pop``` operation then can be simple ```dequeue()``` from the first queue.

When having expensive ```Pop``` method same twist happens in ```Pop``` method and ```Push``` allows simple ```enqueue()```.

```make``` helps generate main and test binaries to run tests or interactive main program.

#### Targets:
  * ```make build```
  * ```make run```
  * ```make test```
  * ```make clean```
