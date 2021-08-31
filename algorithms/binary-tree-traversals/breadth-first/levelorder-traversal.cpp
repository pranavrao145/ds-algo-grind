// This document contains an implementation of the preorder traversal algorithm
// for a binary tree.

// Defintion of a level order traversal: the processing of a tree by depth.
// Fisrt processing the root, then the children of the root, then the
// grandchildren, etc. This is equivalent to a breadth-first search from the
// root of the tree.

// the worst case time complexity of the traversal is O(n), where n is the
// number of nodes in the tree because the algorithm will have to process each
// node once

// Below is an optimized implementation of a level order traversal (using a
// queue), where we print a node once it has been processed

#include "../headers/BST.h" // including the general purpose BST header file to work with binary search trees in this file
#include <iostream>         // for basic input and ouput
#include <queue>            // to use STL queues

// this function is decleared in the BST header file and is used by the BST
// class
BST *minValueNode(BST *node) {
  BST *current = node;

  while (current && current->left)
    current = current->left;

  return current;
}

// this function will take the root of a binary search tree and conduct a level
// order traversal on it, printing out each node once it is processed
void levelOrderTraversal(BST *root) {
  // the strategy is to use a queue to traverse the tree in an optimized
  // fashion. First we are going to check if the current node is null, in which
  // case we are just going to return. We are then going to create a queue, and
  // add the root of the tree to it to start. Then, while the queue is not
  // empty, we're going to loop through the queue and print out the data of the
  // current node, and then remove iit from the queue. Finally we're going to
  // enqueue the current node's children (left to right).

  // if the root is null, return
  if (!root)
    return;

  // create an empty queue for the level order traversal
  std::queue<BST *> q;

  // start by pushing the root node into the queue
  q.push(root);

  // while the queue is not empty
  while (!(q.empty())) {
    // print the front of the queue and remove it from the queue
    BST *node = q.front();
    std::cout << node->data << std::endl;
    q.pop();

    // enqueue the left child
    if (node->left)
      q.push(node->left);

    // enqueue the right child
    if (node->right)
      q.push(node->right);
  }
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

  levelOrderTraversal(
      tree); // run an inorder traversal on the tree to print out all the nodes

  return 0;
}

