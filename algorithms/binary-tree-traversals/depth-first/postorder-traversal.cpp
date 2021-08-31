// This document contains an implementation of the postorder traversal algorithm
// for a binary tree.

// Definition of an postorder traversal: an postorder traversal algorithm is a
// tree traversal algorithm used on a binary tree.

// a postorder traversal is normally used to delete the tree. It can also be
// useful to get the postfix expression of an expression tree. See
// http://en.wikipedia.org/wiki/Reverse_Polish_notation for info on postfix
// expressions.

// the postorder traversal algorithm processes a binary tree by first
// recursively traversing the left subtree, then recursively traversing the
// right subtree, and then finally visiting the root.

// the worst case time complexity of an postorder traversal algorithm is O(n),
// where n is the number of nodes in the tree, because the algorithm does the
// same amount of work for each node, it's just dependent on how many nodes
// there are in the tree.

// Below is an implementation of the postorder traversal algorithm, where we
// print a node once has been processe

#include "../headers/BST.h" // including the general purpose BST header file to work with binary search trees in this file
#include <iostream>         // for basic input and ouput

// this function is decleared in the BST header file and is used by the BST
// class
BST *minValueNode(BST *node) {
  BST *current = node;

  while (current && current->left)
    current = current->left;

  return current;
}

void postOrderTraversal(BST *root) {
  // the strategy is to start at the root of the tree. If the root is null,
  // we return. If not, we recur on the left subtree, then recur on the right
  // subtree, and then finally print the root.

  // if the root is null, return
  if (!root)
    return;

  // recur on the left subtree
  postOrderTraversal(root->left);

  // then recur on the right subtree
  postOrderTraversal(root->right);

  // print out the value of the current node
  std::cout << root->data << std::endl;
}

// main function, which will just be driver code to test out the above traversal
// function
int main(void) {
  BST *tree = new BST(20); // create a new tree with an initial value of 20

  // insert some nodes
  tree = tree->insert(tree, 30);
  tree = tree->insert(tree, 20);
  tree = tree->insert(tree, 40);
  tree = tree->insert(tree, 70);
  tree = tree->insert(tree, 60);
  tree = tree->insert(tree, 80);

  postOrderTraversal(
      tree); // run an postorder traversal on the tree to print out all the nodes

  return 0;
}
