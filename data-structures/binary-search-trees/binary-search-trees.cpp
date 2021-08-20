// This document contains an implementation of a binary search tree. It will
// contain all the normal functions one would expect to conduct on a binary
// search tree, as well as a function to initialize a sample binary search tree


// Definition of a linked list (Wikipedia):
// Binary Search Tree is a node-based binary tree data structure which has the following properties:  
// - The left subtree of a node contains only nodes with keys lesser than the node’s key.
// - The right subtree of a node contains only nodes with keys greater than the node’s key.
// - The left and right subtree each must also be a binary search tree. 
// - There must be no duplicate nodes.

// first we need a Node class, which will contain a key and a pointer
// to its right and left children. We'll also give it a constructor 
// to make life easier.

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int key) { 
            this->data = key;
            this->left = nullptr; // initially make the pointer a nullptr
            this->right = nullptr; // initially make the pointer a nullptr
        }
};

// we also need a BinarySearchTree class, which will represent the tree
// itself. This will contain a pointer to the root node of the tree as well
// as functions to search the tree, insert into the tree, and delete from the
// tree. We will also include a utility function to print the data in the list.

class BinarySearchTree {
        // the tree needs a head. Initialize to nullptr so we can check value later.
        Node *root = nullptr;
};
