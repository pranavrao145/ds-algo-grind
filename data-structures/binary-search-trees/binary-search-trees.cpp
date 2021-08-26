// This document contains an implementation of a binary search tree. It will
// contain all the normal functions one would expect to conduct on a binary
// search tree, as well as a function to initialize a sample binary search tree

// Definition of a linked list (Wikipedia):
// Binary Search Tree is a node-based binary tree data structure which has the
// following properties:
// - The left subtree of a node contains only nodes with keys lesser than the
// node’s key.
// - The right subtree of a node contains only nodes with keys greater than the
// node’s key.
// - The left and right subtree each must also be a binary search tree.
// - There must be no duplicate nodes.

// since, by definition, a binary search tree's left and right children
// must also be a binary search tree, we don't need to make an explicit
// class for a node. Instead we can just use a single binary search tree class
// In this class we'll define a constructor, a search method, an insert method
// and a delete method. We'll also include a utility function to print the
// binary search tree using inorder traversal.

// for all methods in this data structure, the worst case time complexity is
// O(n). In general though, the worst case time complexity is O(h) where h
// is the height of the tree.

#include <iostream> // basic input and output

class BST {
  int data;
  BST *left, *right;

  // constructor for easy creation of a BST (or a BST node)
  BST(int data) { this->data = data; }

  // this function will take a root node and a key. It will search the tree
  // for the first occurence of a node with a given key, and return that node
  // when it is found. If a node with that key is not found, this function
  // will return nullptr
  BST *search(BST *root, int key) {
    // the strategy is to start at the root (given) node. If the root is
    // the node we're looking for or if it is nothing return the node (therefore
    // fulfulling the return conditions of this function). If it is not the
    // node, check if the key of the root is less than the desired key,
    // and recurse right if so. Else recuse left.

    // base case: the root is the node we're looking for or is nullptr
    if (!root || root->data == key)
      return root;

    // if the key is greater than the root's key, recurse right
    if (root->data < key)
      return search(root->right, key);

    // if the key is less than the root's key, recurse left
    return search(root->left, key);
  }
};
