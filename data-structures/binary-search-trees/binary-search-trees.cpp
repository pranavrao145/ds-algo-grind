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
// In this class we'll define a search method, an insert methodm and a delete
// method. We'll also include a utility function to print the binary search tree
// using inorder traversal

// for all methods in this data structure, the worst case time complexity is
// O(n) where n is the height of the binary search tree. However, in the best
// case scenario, the time complexity of these functions is O(log(n)) because
// the height of the tree (with the same number of elements) would be log(n)
// rather than the n we had before

class BST {
public:
  int data;
  BST *left, *right;

  // this function will take a node and a desired key, and search the tree
  // recursively for a node with that key. If such a node exists, it will
  // return this node. Else, it will return a nullptr
  BST *searchTree(BST *node, int data) {
    // this is the strategy: if the current node is null, the node is
    // not found, so return null. If the node's key is the one we're looking
    // for, we return the node. If the current node's key is greater than the
    // desired key, we rerun this function on the right subtree, else on the
    // left subtree.

    // check for nullptr
    if (node == nullptr)
      return nullptr;

    if (node->data == data)
      return node;

    if (node->data > data)
      return searchTree(node->right, data);

    return searchTree(node->left, data);
  }
};
