// This document contains an implementation of a queue using an array. It will
// contains all the normal functions one would expect to conduct on a queue, as
// well as a function to initialize the sample queue

// Definition of a queue: a queue is a linear data structure that serves as a
// container of objects that are inserted and removed acording to the FIFO
// (first in, first out) principle.

// A stack implemented using an array will normally contain a pointer to an
// array of a fixed size, a capacity, a pointer to the front of the queue, if
// any, a pointer to the back of the queue, if any, and the current size of the
// queue

#include <iostream> // for basic input and output

// We need a queue class, which will represent the queue itself. It will contain
// function to enqueue data to the queue, dequeue data from the queue, peek the
// front element of the queue without dequeueing, and finally utility functions
// to check if the queue is empty or full. We'll also include a constructor to
// make life easier
class Queue {
public:
  int *arr;
  int capacity;
  int front = 0;    // points to the front element of the queue (if any)
  int rear = -1;    // points to the last element in the queue
  int elements = 0; // number of elements currently in the queue

  Queue(int size) {
    this->arr = new int[size];
    this->capacity = size;
  }
};
