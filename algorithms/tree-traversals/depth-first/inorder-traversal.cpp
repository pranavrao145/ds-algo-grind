// This document contains an implementation of the inorder traversal algorithm.
// for a binary tree.

// Definition of an inorder traversal: an inorder traversal algorithm, sometimes
// known as a symmetric traversal, is a tree traversal algorithm used on a
// binary tree.

// In the case of binary search tree, the inorder traversal gives the nodes in
// non-decreasing order. To get the nodes of a BST in a non-decreasing order, we
// can use a reversed variation of the inorder traversal algorithm.

// the inorder traversal algorithm processes a binary tree by first recursively
// processing the left subtree, then processing the root, then processing the
// right subtree.

// the worst case time complexity of an inorder traversal algorithm is O(n),
// where n is the numebr of nodes in the tree, because the algorithm does the
// same amount of work for each node, it's just dependent on how many nodes
// there are in the tree.

// Below is an implementation of the inorder traversal algorithm, where we
// print every processed node

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

void inOrderTraversal(BST *root) {
  // the strategy is to start at the root of the tree. If the root is null,
  // we reutrn. If not, we start recurse on the left subtree, print out the
  // value of the current root (traverse the root), and finally recurse on the
  // right subtree

  // if the root is null, return
  if (!root)
    return;

  // first recur on the left subtree
  inOrderTraversal(root->left);

  // print out the value of the current node
  std::cout << root->data << std::endl;

  // then recur on the right subtree
  inOrderTraversal(root->right);
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

  inOrderTraversal(
      tree); // run an inorder traversal on the tree to print out all the nodes

  return 0;
}
