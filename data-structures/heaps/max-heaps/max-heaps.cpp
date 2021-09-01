// This document contains an implementation of a binary max heap

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
// priority queue class, which is the most common implementation for a heap. This
// way it is easier to show the max heap in action
class PriorityQueue {};
