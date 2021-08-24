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

class BST {
public:
  int data;
  BST *left, *right;

  // constructor with no predefined left and right
  BST(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }

  // constructor with a predefined left and right
  BST(int data, BST *left, BST *right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  // this function will take a root node and a desired key, and search the tree
  // recursively for a node with that key. If such a node exists, it will
  // return this node. Else, it will return a nullptr
  BST *searchTree(BST *root, int data) {
    // this is the strategy: if the current node is null, the node is
    // not found, so return null. If the node's key is the one we're looking
    // for, we return the node. If the current node's key is greater than the
    // desired key, we rerun this function on the right subtree, else on the
    // left subtree.

    // check for nullptr
    if (!root)
      return nullptr;

    if (root->data == data)
      return root;

    if (root->data > data)
      return searchTree(root->right, data);

    return searchTree(root->left, data);
  }

  // this function will take a root node and a desired key, and insert a node
  // with this key into the the tree in the right place. This function will
  // return a pointer to the newly formed binary search tree.
  BST *insert(BST *root, int key) {
    // the node will always be a leaf, so the strategy is to check until the
    // point where there's no child node, at which point we can insert the new
    // node

    // if the root doesn't exists (i.e. the tree doesn't exist or the previous
    // node had no child), we can insert here because the new node must be a
    // leaf
    if (!root) {
      BST *node = new BST(key); // make a new node
    }
    // if the given key is greater than the node's key, go to the right
    // subtree
    else if (root->data < key) {
      root->right = insert(root->right, key);
    }
    // if the given key is less than the node's key, go to the left
    // subtree
    else if (root->data > key) {
      root->left = insert(root->left, key);
    }

    return root;
  }
};

