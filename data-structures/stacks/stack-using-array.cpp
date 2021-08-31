// This document contains an implementation of a stack using an array. It will
// contains all the normal functions one would expect to conduct on a stack, as
// well as a function to initialize the sample stack

// Definition of a stack: a stack is a linear data structure that serves as a
// container of object that are inserted and removed according to the LIFO (last
// in, first out) rule.

// A stack implemented using an array will normally contain a pointer to an
// array, an integer to represent the how many elements are currently in the
// stack, and then an integer to represent the capacity of the stack.

#include <iostream> // for basic input and output

// We need a stack class, which will represent the stack itself. It will contain
// functions to push to the stack, pop from the stack, utility functions to see
// if the stack is full or empty, a function to peek the top value of the stack.
// We'll also include a constructor to make life easier
class Stack {
public:
  int *arr;
  int elements =
      -1; // initialize elements to -1 to signify no elements in stack
  int capacity;

  Stack(int size) {
    this->arr = new int[size];
    this->capacity = size;
  }

  // this is utility function to check if the stack is full or not
  bool isFull() {
    // return true if the number of elements is the capcity, else return false
    return this->elements == this->capacity - 1;
  }

  // this is utility function to check if the stack is empty or not
  bool isEmpty() {
    // return true if the number of elements -1, else return false
    return this->elements == -1;
  }

  // this function will take an integer and push it to the stack
  void push(int elem) {
    // if the stack is already full, return
    if (this->isFull()) {
      std::cout << "Stack overflow. Refusing to push." << std::endl;
      return;
    }

    // insert the element into the stack by putting it in the array next to the
    // last element in the stack (the top)
    this->arr[++elements] = elem;
  }

  // this function will pop an element from the stack
  void pop() {
    // if the stack is already empty, return
    if (this->isEmpty()) {
      std::cout << "Stack overflow. Refusing to pop." << std::endl;
      return;
    }

    // decrease stack size by 1. No need to actually delete the element or set
    // it to zero because it will be overwritten when you try to push anyway
    this->elements--;
  }

  // this function will return the top element of the stack
  int peek() {
    // if the stack is not empty, then return the top element of the array
    if (!isEmpty())
      return this->arr[elements];
    // if the array is empty and an element cannot be peeked, exit with failure
    else
      exit(EXIT_FAILURE);
  }
};

// main function, which is just some driver code to test out the above
int main() {
  Stack *stack = new Stack(5); // create a new stack with a capacity of 10

  // push some elements
  stack->push(3);
  stack->push(4);
  stack->push(5);
  stack->push(6);
  stack->push(7);
  stack->push(100); // this causes a stack overflow

  // pop some stuff from the stack
  stack->pop();
  stack->pop();

  // push again
  stack->push(100);

  // print out some information
  std::cout << "Size of stack: " << stack->capacity << std::endl;
  std::cout << "Elements currently in stack: " << stack->elements << std::endl;

  stack->pop(); // pop again

  // the peek the top element in the stack
  std::cout << stack->peek() << std::endl;

  // check if the stack is empty
  if (stack->isEmpty())
    std::cout << "The stack is empty." << std::endl;
  else
    std::cout << "The stack is not empty." << std::endl;

  return 0;
}
