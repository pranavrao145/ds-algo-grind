// This document contains an implementation of a stack using an linked list. It
// will contain all the normal functions one would expect to conduct on a
// stack, as well as a function to initialize the sample stack.

// Definition of a stack: a stack is a linear data structure that serves as a
// container of object that are inserted and removed according to the LIFO (last
// in, first out) rule.

// In a stack implemented by a linked list, the stack is actually just a pointer
// to the head of a linked list where pushing and popping happens. Sometimes
// a counter to keep track of the list's size is also included.

// A stack implemented using a linked list has an advantage over an array in
// that the stack can grow and shrink as needed

// for all the methods in this data structure, the time complexity is O(1)
// beacuse we are doing a constant amount of work, no matter the number of elements
// in the stack

#include <iostream> // for basic input and output

// since we are implementing the stack with a linked list, we first need a node
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

// then we need a stack class, which will represent the stack itself. It will
// contain functions to push to the stack, pop from the stack, utility functions
// to see if the stack is empty, a function to peek the top value of the stack.
// We'll also include a constructor to make life easier. Since this is a linked
// list implementation of the stack, we'll exclude anything that has to do with
// the max capacity of the stack, as the linked list is dynamic in size.
class Stack {
public:
  Node *top = nullptr; // a node pointer (initially nullptr to keep track of the
                       // top element (head of the linked list))
  int size = 0; // to keep track of the size (number of elements) currently in
                // the stack. Starts at 0

  // this is a utility function to check if the stack is empty
  bool isEmpty() { return this->size == 0; }

  // this function will push to the top of the stack. Essentially, this is
  // a linked list function to insert at the head. Refer to the document on
  // singly linked lists for more information.
  void push(Node *node) {
    if (!node)
      return;

    if (!this->top)
      this->top = node;
    else {
      node->next = this->top;
      this->top = node;
    }

    this->size++; // increment the number of elements in the stack
  }

  // this function will pop to the top of the stack. Essentially, this is
  // a linked list function to delete the head of a linked list.
  void pop() {
    // the logic is to check if the stack is empty. If it is not empty, then
    // make the current top's successor the new top of the stack. However, to
    // free the space allocated to the old top, the old top will have to be
    // stored in a temporary variable before this changes is made

    if (this->isEmpty()) { // if the stack is empty
      std::cout << "Stack underflow. Refusing to pop." << std::endl;
      return;
    }

    Node *temp = this->top; // store the current top of the stack in a temp
                            // variable to free later
    this->top =
        this->top->next; // change the top to the node that was after the top

    delete temp; // free up the space taken by the old top

    this->size--; // decrement the number of elements in the stack
  }

  // this function will return the the value in the top element of the stack if
  // it is not empty. If it is, it will exit with a failure.
  int peek() {
    // if the stack is not empty, then return the top element of the array
    if (!this->isEmpty())
      return this->top->data;
    // if the list is empty and an element cannot be peeked, exit with failure
    else
      exit(EXIT_FAILURE);
  }
};

// main function, which is just some driver code to test out the above
int main() {
  Stack *stack = new Stack(); // create a new stack

  // push some elements
  stack->push(new Node(3));
  stack->push(new Node(4));
  stack->push(new Node(5));
  stack->push(new Node(6));
  stack->push(new Node(7));

  // pop some stuff from the stack
  stack->pop();
  stack->pop();

  // push again
  stack->push(new Node(100));

  // print out some information
  std::cout << "Elements currently in stack: " << stack->size << std::endl;

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
