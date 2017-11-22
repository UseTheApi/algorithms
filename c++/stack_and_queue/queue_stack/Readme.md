# Queue from Stack

#### Task
Implement a Queue data structure using standard implementation of stack.

#### Notes
Queue data structure may be implemented with 2 stacks. When implementing Queue through Stack there is a tradeoff. We only can make 1 of Queue operations effective - ```Enqueue``` or ```Dequeue```.

When having expensive ```Enqueue``` method - we ```pop()``` all values from 1 stack into the second stack, adding a node to the first stack and then ```pop()``` everything from the second stack back to the first one. In this case ```Dequeue``` operation will only have to ```pop()```.

When having expensive ```Dequeue``` method same twist happens in ```Dequeue``` method and ```Enqueue``` allows simple ```push()```.

```make``` helps generate main and test binaries to run tests or interactive main program.

#### Targets:
  * ```make build```
  * ```make run```
  * ```make test```
  * ```make clean```
