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

// for all the methods in this data structure, the time complexity is O(1)
// beacuse we are doing a constant amount of work, no matter the number of
// elements in the queue

#include <iostream> // for basic input and output

// We need a queue class, which will represent the queue itself. It will contain
// function to enqueue data to the queue, dequeue data from the queue, peek the
// front element of the queue without dequeueing, and finally utility functions
// to check if the queue is empty or full. We'll also include a constructor to
// make life easier.
class Queue {
public:
  int *arr;
  int capacity;     // capacity og the queue
  int front = 0;    // position of the first element in the queue (if any)
  int rear = -1;    // the position of the last element of the queue
  int elements = 0; // the number of elements currently in the queue

  Queue(int size) {
    this->arr = new int[size];
    this->capacity = size;
  }

  // this is utility function to check if the stack is full or not
  bool isFull() {
    // return true if the number of elements is the capcity, else return false
    return this->rear == this->capacity - 1;
  }

  // this is utility function to check if the stack is empty or not
  bool isEmpty() {
    // return true if the number of elements is 0, else return false
    return this->elements == 0;
  }

  // this function will take an integer item and enqueue it to the queue. Note
  // that this solution is optimized, and versions of this function exist that
  // are O(n), where all the elements are shifted. This is in fact not
  // necessary, as showing here
  void enqueue(int elem) {
    // the strategy is to use the front and rear pointers of this data
    // structure, without ever actually shifting any elements, thereby keeping
    // everything in O(1) time. Once we check that the queue is not full, we
    // will calculate the new rear position by adding one to the rear pointer
    // and modding it by the capacity (in case the rear pointer exceeds said
    // capacity) and then just insert the new element at that position instead.
    // Since we keep track of exactly where the rear is, we can just access that
    // element by that index instead of shifting and relying on it's acutal
    // position in the array.

    // if the queue is already full, return
    if (this->isFull()) {
      std::cout << "Queue overflow. Refusing to enqueue." << std::endl;
      return;
    }

    this->rear = (rear + 1) %
                 this->capacity;  // calculate the new rear position, accounting
                                  // for if the rear exceeds the capacity
    this->arr[this->rear] = elem; // put the element at the new rear position
    this->elements++;             // increment the number of elements
  }

  // this function will take an integer item and enqueue it to the queue. Note
  // that this solution is optimized, and versions of this function exist that
  // are O(n), where all the elements are shifted. This is in fact not
  // necessary, as showing here
  void dequeue() {
    // this function employs a similar strategy to the enqueue function. Instead
    // of shifting elements and relying on their actual positions in the array,
    // we'll simply keep track of where the front and back of the queue are and
    // access elements based on that.

    // if the queue is already empty, return
    if (this->isEmpty()) {
      std::cout << "Queue underflow. Refusing to dequeue." << std::endl;
      return;
    }

    this->front = (this->front + 1) %
                  this->capacity; // calculate the new front, accounting for if
                                  // the front exceeds the capacity
    this->elements--;             // decrement the number of elements
  }

  // this function will return the top element of the queue if it is not empty.
  // If it is, it will exit with a failure.
  int peek() {
    // if the queue is not empty, then return the top element of the array
    if (!this->isEmpty())
      return this->arr[this->front];
    // if the array is empty and an element cannot be peeked, exit with failure
    else
      exit(EXIT_FAILURE);
  }
};

// main function, which is just some driver code to test out the above
int main() {
  // create a queue of capacity 5
  Queue *q = new Queue(5);

  // enqueue some elements
  q->enqueue(1);
  q->enqueue(2);
  q->enqueue(3);

  // peek queue
  std::cout << "Front of queue: " << q->peek() << std::endl;

  // dequeue from the queue
  q->dequeue();

  // enqueue again
  q->enqueue(4);

  // print out size
  std::cout << "The queue size is " << q->elements << std::endl;

  // dequeue some more elements
  q->dequeue();
  q->dequeue();
  q->dequeue();

  // check if the queue is empty
  if (q->isEmpty())
    std::cout << "The queue is empty." << std::endl;
  else
    std::cout << "The queue is not empty." << std::endl;

  return 0;
}
