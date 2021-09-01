# Heaps

## Background
Heaps are normally used to implement something called a priority queue. Before learning
heaps, it's important to understand what exactly a priority queue is. 

## Priority Queues
A priority queue is
an ADT (Abstract Data Type) for maintaining a set of elements, each one having a "priority"
associated with it. An element with a high priority is served before an element with low priority.
If two elements in the queue have the same priority, they will be served in accordance with their
position in the queue.


### Operations
A priority queue typically contains three operations:
    * push - pushes an element into the set - usually an O(log(n)) operation
    * top - returns the element with the highest or lowest priority (but does not modify the queue) - this is an O(1) operation.
    * pop - this removes and returns the element with the highest (or lowest) priority - usually an O(log(n)) operation.

# Type of Heaps
There are two types of heaps: min heaps and max heaps. This folder will cover both.
