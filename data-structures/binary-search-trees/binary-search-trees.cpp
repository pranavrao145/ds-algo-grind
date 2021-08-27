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

  // this function will take a root node and a key. It will insert a node
  // with the given key into the tree and return a pointer to the root of the
  // new tree
  BST *insert(BST *root, int key) {
    // the strategy is to first check if the root (current node) exists or not
    // if not, then we can insert the node at this point. So we just make a new
    // BST and return a pointer to it. However, if it does exist, we have to
    // traverse further. So we will first check if the value we want to insert
    // is greater than the one of the current node. If so, we recurse right
    // and repeat the process there until we encounter null (handled by base
    // case). Else we recurse left. After everything is done, we should return
    // the root node, which will be the root of the new tree (and also the old
    // tree).

    // base case: root is null, so we make a new BST (node)
    if (!root)
      return new BST(key);

    // if the key is greater than the current node's data, recurse right
    if (key > root->data)
      root->right = insert(root->right, key);
    // else recurse left
    else
      root->left = insert(root->left, key);

    // once everything is done, return the root node
    return root;
  }

  // this function will take a root node and a key. It will delete the first
  // occurence of a node in the tree and return the root of the new tree.
  BST *deleteNode(BST *root, int key) {
    // the strategy is to first check if the root (current node) is null.
    // If that's the case, there's nothing to, so we can just return the root.
    // If it is not null, we have to continue our search or operate on this
    // node, depending on the situation. If this node is not the node we need
    // to delete, we will continue to search. We will check if the key is
    // less than the data in the root. If so, we will recurse left, else right.
    // If this is the node we need to delete (i.e. the value of the key and the
    // data inside the node are the same), then we proceed to delete it.

    // There are three possibilities for delete:
    //    1. The node to be deleted is a leaf, in which case we just remove it
    //    from the tree
    //    2. The node to be deleted has only one child, in which case we will
    //    copy the child to the node and delete the child
    //    3. Node to be deleted has two children. In this case, we need to
    //    find the current node's indorder successor. Refer to this link for
    //    information on inorder successors:
    //        https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
    //    We will use the inorderSucessor function from there to find the
    //    inorder successor. Refer to function definition for a more detailed
    //    explanation on the algorithm. Once we find the inorder sucessor, we
    //    simply copy the contents of the inorder sucessor to the current node
    //    and then delete the inorder successor. Note: you actually only need to
    //    use the inorder successor when the right child is not empty.

    // TODO: Figure out why the that's the case^

    // base case: root is null (just return the root)
    if (!root) {
      return root;
    }

    // recursive calls for ancestors of node to be deleted. Same logic: if
    // the data in the root is greater than the key, recurse left, else recurse
    // right
    if (root->data > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->data < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
 
  }
};
