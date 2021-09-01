// This document contains an implementation of a queue using an array. It will
// contains all the normal functions one would expect to conduct on a queue, as
// well as a function to initialize the sample queue

// Definition of a queue: a queue is a linear data structure that serves as a
// container of objects that are inserted and removed acording to the FIFO
// (first in, first out) principle.

// In a queue implemented using a linked list, it is necessary to keep track of
// the front and the rear for efficient enqueuing and dequeueing in O(1) time.
// Sometimes a counter to keep track of the list's size is also included.

// A queue implemented using a linked list has an advantage over an array in
// that the queue can grow and shrink as needed.

// for all the methods in this data structure, the time complexity is O(1)
// beacuse we are doing a constant amount of work, no matter the number of
// elements in the queue

#include <iostream> // for basic input and output

// since we are implementing the queue with a linked list, we first need a node
// class
class Node {
public:
  int data;
  Node *next;

  Node(int key) {
    this->data = key;
    this->next = nullptr; // initially make the pointer a nullptr
  }
};

// then we need a queue class, which will represent the queue itself. It will
// contain function to enqueue data to the queue, dequeue data from the queue,
// peek the front element of the queue without dequeueing, and finally utility
// functions to check if the queue is empty. We'll also include a constructor to
// make life easier. Since this is a linked list implementation of the queue,
// we'll exclude anything that has to do with the max capacity of the queue, as
// the linked list is dynamic in size.
class Queue {
public:
  Node *front = nullptr; // initially make the front pointer a nullptr
  Node *rear = nullptr;  // initially make the rear pointer a nullptr
  int size = 0; // to keep track of the size (number of elements) currently in
                // the queue. Starts at 0.

  // this is a utility function to check if the queue is empty
  bool isEmpty() { return this->size == 0; }

  // this function will take a pointer to a node and enqueue it to the queue.
  // This is basically a linked list function to insert at the tail. Refer to
  // the document on singly linked lists for more information.
  void enqueue(Node *node) {
    if (!this->front) {
      // initialize both the front and the rear if the queue is empty.
      this->front = node;
      this->rear = node;
    } else {
      this->rear->next = node;
      this->rear = node;
    }

    this->size++; // increment the number of elements in the list
  }

  // this is a function to dequeue the front element from the queue
  void dequeue() {
    // the logic is to check if the queue is empty. If it is not empty, then
    // advance the front of the queue to the next of the current front node.
    // However, to free the space allocated to the old front, the old front will
    // have to be stored in a temporary variable before this changes is made.
    // Also, a special case will have to exist in case the list becomes empty,
    // in which case we must nullify both the front and the rear

    if (this->isEmpty()) { // if the queue is empty
      std::cout << "Queue underflow. Refusing to dequeue." << std::endl;
      return;
    }

    Node *temp =
        this->front; // store the front in a temp node for deletion later

    // advance the front node to the next of the current front
    this->front = this->front->next;

    // special case: the list becomes empty, make rear nullptr too
    if (!this->front)
      this->rear = nullptr;

    delete temp; // free up the space taken by the old front

    this->size--; // decrement the number of elements in the queue
  }

  // this function will return the the value in the top element of the queue if
  // it is not empty. If it is, it will exit with a failure.
  int peek() {
    // if the queue is not empty, then return the top element of the array
    if (!this->isEmpty())
      return this->front->data;
    // if the list is empty and an element cannot be peeked, exit with failure
    else
      exit(EXIT_FAILURE);
  }
};

// main function, which is just some driver code to test out the above
int main() {
  // create a queue of capacity 5
  Queue *q = new Queue();

  // enqueue some elements
  q->enqueue(new Node(1));
  q->enqueue(new Node(2));
  q->enqueue(new Node(3));

  // peek queue
  std::cout << "Front of queue: " << q->peek() << std::endl;

  // dequeue from the queue
  q->dequeue();

  // enqueue again
  q->enqueue(new Node(4));

  // print out size
  std::cout << "The queue size is " << q->size << std::endl;

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
