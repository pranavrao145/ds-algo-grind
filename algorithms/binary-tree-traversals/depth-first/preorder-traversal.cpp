// This document contains an implementation of the preorder traversal algorithm
// for a binary tree.

// Definition of an preorder traversal: an preorder traversal algorithm is a
// tree traversal algorithm used on a binary tree.

// A preorder traversal is normally used to create a copy of the tree. 

// the preorder traversal algorithm processes a binary tree by first visiting the 
// root, recursively traversing the left subtree, and then finally recursively traversing
// the right subtree

// the worst case time complexity of an preorder traversal algorithm is O(n),
// where n is the number of nodes in the tree, because the algorithm does the
// same amount of work for each node, it's just dependent on how many nodes
// there are in the tree.

// Below is an implementation of the preorder traversal algorithm, where we
// print a node once has been processed

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

void preOrderTraversal(BST *root) {
  // the strategy is to start at the root of the tree. If the root is null,
  // we return. If not, we print out the value of the current node. Then we recur
  // on the left subtree, and then on the right subtree
  
  // if the root is null, return
  if (!root)
    return;
  
  // print out the value of the current node
  std::cout << root->data << std::endl;

  // then recur on the left subtree
  preOrderTraversal(root->left);


  // then recur on the right subtree
  preOrderTraversal(root->right);
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

  preOrderTraversal(
      tree); // run an preorder traversal on the tree to print out all the nodes

  return 0;
}

