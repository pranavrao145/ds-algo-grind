// This document contains an implementation of a binary max heap. It will
// contain all the normal functions one would expect to conduct on a max heap,
// as well as a function to initialize a sample max heap in the form of a
// priority queue.

// Definition of a heap (Wikipedia): a heap is a specialized tree-based data
// structure which is essentially an almost complete tree that satisfies the
// heap property (see below).

// A binary heap must satisfy two conditions
//  1. STRUCTURAL PROPERTY: the binary heap must be a full binary tree (meaning
//  all the levels of the tree are completely full (except maybe the last level,
//  which must be filled from left to right if it is not complete).
//  2. HEAP PROPERTY: the key stored in each node of the binary heap is either
//  "greater than or equal to" or "less than or equal to" the keys in the node's
//  children

// Binary heaps have the smallest possible height of log(n), where n is the
// total number of nodes in the heap.

// In a max heap, the keys of the parent nodes are ALWAYS greater than or equal
// to those of the children, and the highest key is in the root node. For a
// priority queue, this means that the root node is always the highest priority.

#include <iostream> // for basic input and output

// even though a binary heap is a full binary tree, we don't normally use
// a binary tree to implement said heap. Instead, we store keys in an array
// and use their relative positions within that array to represent parent-child
// relationships

// instead of explicitly defining a heap class, we are going to define a
// priority queue class, which is the most common implementation for a heap.
// This way it is easier to show the max heap in action.

// this class will contain functions to heapify_up and heapify_down (see below),
// functions to push and pop to the heap, a function to peek the top of the
// heap, and a utility function to check if the heap is empty. We'll also
// include a constructor to make life easier
class PriorityQueue {
private:
  int *arr; // the array that actually represent the heap

  // IMPORTANT NODE:
  // because this is a heap and it satisfies the properties of a heap, there is
  // actually a consistent formula to find things like the parent, left child,
  // and right child of any given node.

  // this function will take the index of a node and return index of the parent
  // of the node
  int parent(int i) {
    // the formula to get the parent node of any given node is floor((index of
    // node - 1)/2)
    return (i - 1) / 2;
  }

  // this function will take the index of a node and return the index of the
  // right child of the node
  int right(int i) {
    // the formula to get the right node of any given node is (2 times the
    // index) + 2
    return (2 * i) + 2;
  }

  // this function will take the index of a node and return the index of the
  // left child of the node
  int left(int i) {
    // the formula to get the left node of any given node is (2 times the
    // index) + 1
    return (2 * i) + 1;
  }

  // HEAPIFY OPERATIONS
  // heapify operations are extremely important in a heap. They are used to
  // correct a heap that does violates the properties of a heap (see above).
  // There are two ways to heapify a violating heap.

  // first we have heapify down. Heapify down is invoked if an element at index
  // i violates a heap property in with its two direct children. It converts the
  // binary tree, with its root at index i, and converts it into a heap by
  // moving said node down the tree (hence the name, heapify down).

  // this function will take an index i, and turn the binary tree rooted at i
  // into a heap by moving the node at this index down the tree

public:
  int size =
      0; // to keep track of the size (number of elements) currently in the heap
};
