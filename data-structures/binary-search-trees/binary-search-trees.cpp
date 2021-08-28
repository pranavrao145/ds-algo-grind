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

class BST;

BST *minValueNode(BST *node);

class BST {
public:
  int data;
  BST *left, *right;

  // constructor for easy creation of a BST (or a BST node)
  BST(int data) { this->data = data; }

  // function to conduct an inorder traversal and print out the tree. For
  // more detail on inorder traversals, see the algorithms section of this
  // repo where this will be covered
  void inOrderTraversal(BST *root) {
    if (root) {
      inOrderTraversal(root->left);
      std::cout << root->data << std::endl;
      inOrderTraversal(root->right);
    }
  }

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

    // Note: this function uses the delete operator and assumes any objects
    // were allocated memory with the new operator.

    // There are three possibilities for delete:
    //    1. The node to be deleted is a leaf, in which case we just remove it
    //    from the tree
    //    2. The node to be deleted has only one child, in which case we will
    //    copy the child to the node and delete the child
    //    3. In the case Node to be deleted has two children. Just like the
    //    second subcase, we don't actually delete the actual node here, but
    //    rather, we copy the appropriate successor's value into this node and
    //    delete the successors instead. However, since this node has 2
    //    children, we don't just copy the child into the parent and delete the
    //    child. Instead, we find something called the inorder successor, which
    //    is basically the next node from the current one in an inorder
    //    traversal.

    //    Refer to this link for information on inorder successors in a BST:
    //      https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/

    //    Refer to this link (under the "A good way to delete a key section")
    //    for an example case of how the third option works:
    //      https://inst.eecs.berkeley.edu/~cs61bl/r//cur/binary-search-trees/deletion-bst.html?topic=lab17.topic&step=1&course=

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
    } else if (root->data < key) {
      root->right = deleteNode(root->right, key);
      return root;
    } else {
      // if this node has the same data as the given key, this is what we have
      // to delete (i.e. check the three scenarios)

      // if the node has no child
      if (!root->left && !root->right)
        return nullptr;
      // if the node only has one child (right or left is null)
      else if (!root->left) {
        BST *temp =
            root->right; // store a temp node as the current root's right child
        delete root;     // delete the root
        return temp;     // return the temp node as the root of the new tree
      } else if (!root->right) {
        BST *temp =
            root->left; // store a temp node as the current root's left child
        delete root;    // delete the root
        return temp;    // return the temp node as the root of the new tree
      }

      // finally, if both child nodes exist. find the inorder sucessor (smallest
      // in the right subtree), copy it's data to the root, and delete the
      // inorder successor

      // find the inorder successor (smallest child in right subtree)
      BST *temp = minValueNode(root->right);

      // copy the inorder successor's content to this node
      root->data = temp->data;

      // delete the inorder successor
      root->right = deleteNode(root->right, temp->data);
    }

    // return the root of the new tree
    return root;
  }
};

// this is a utility function that will take a non-empty binary search tree
// and return the smallest key value found in that tree. This assumes the right
// subtree in the BST is not null, and therefore does not search the whole
// binary search tree. (See link above on inorder successors in BSTs)
BST *minValueNode(BST *node) {
  BST *current = node; // store the current node

  // loop throught to find the leftmost leaf of the tree
  while (current && current->left)
    current = current->left;

  // return the leftmost leaf of the tree
  return current;
}

int main(int argc, char *argv[]) {
  BST *tree = new BST(20); // create a new tree with an initial value of 20

  // insert some nodes
  tree = tree->insert(tree, 30);
  tree = tree->insert(tree, 20);
  tree = tree->insert(tree, 40);
  tree = tree->insert(tree, 70);
  tree = tree->insert(tree, 60);
  tree = tree->insert(tree, 80);

  // initial traversal of the tree
  std::cout << "Inorder traversal of tree:" << std::endl;
  tree->inOrderTraversal(tree);

  // traversal and printing of the tree after a few deletions
  tree = tree->deleteNode(tree, 20);
  std::cout << "After deleting 20:" << std::endl;
  tree->inOrderTraversal(tree);

  tree = tree->deleteNode(tree, 30);
  std::cout << "After deleting 30:" << std::endl;
  tree->inOrderTraversal(tree);

  tree = tree->deleteNode(tree, 50);
  std::cout << "After deleting 50:" << std::endl;
  tree->inOrderTraversal(tree);

  return 0;
} 
