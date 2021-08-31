// This document contains an implementation of a stack using an linked list. It
// will contains all the normal functions one would expect to conduct on a
// stack, as well as a function to initialize the sample stack.

// Definition of a stack: a stack is a linear data structure that serves as a
// container of object that are inserted and removed according to the LIFO (last
// in, first out) rule.

// In a stack implemented by a linked list, the stack is actually just a pointer 
// to the head of a linked list where pushing and popping happens. Sometimes
// a counter to keep track of the list's size is also included. 

// A stack implemented using a linked list has an advantage over an array in that
// the stack can grow and shrink as needed

#include "./headers/linked-list.h" // including the general purpose linked-list header file to work with binary search trees in this file
#include <iostream> // for basic input and output

// We need a stack class, which will represent the stack itself. It will contain
// functions to push to the stack, pop from the stack, utility functions to see
// if the stack is full or empty, a function to peek the top value of the stack.
// We'll also include a constructor to make life easier
class Stack {
};
