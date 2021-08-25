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
// O(n) where n is the height of the binary search tree. However, in the best
// case scenario, the time complexity of these functions is O(log(n)) because
// the height of the tree (with the same number of elements) would be log(n)
// rather than the n we had before

#include <iostream> // basic input and output

class BST {
  int data;
  BST *left = nullptr, *right = nullptr;

  BST(int data) { this->data = data; }

  // function to traverse the tree in order. This will be covered in another
  // file later on (in the algorithms section).
  void inOrderTraveral(BST *root) {
    if (root) {
      inOrderTraveral(root->left);
      std::cout << root->data << " ";
      inOrderTraveral(root->right);
    }
  }

  // this function will take a root node and value, and insert a new node
  // with that value into the tree where it's supposed to be
  BST *insert(BST *node, int key) {
    // the strategy is: if the node (which will initially be the root node)
    // is not null, the recurse down the tree to figure out where the node
    // should be. If the given key is greater than the current node's key,
    // then call the insert function on the left subtree, else the right
    // subtree. If the node is null, then simply return the node itself

    // if the current node is null
    if (!node)
      return new BST(key);

    // otherwise, recurse down the tree
    if (key < node->data)
      node->left = insert(node->left, key);
    else if (key > node->data)
      node->right = insert(node->right, key);

    // return the unchanged node pointer
    return node;
  }
};
