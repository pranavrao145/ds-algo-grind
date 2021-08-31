#include <iostream> // basic input and output
 
class BST;

BST *minValueNode(BST *node);

class BST {
public:
  int data;
  BST *left, *right;

  BST(int data) { this->data = data; }

  void inOrderTraversal(BST *root) {
    if (root) {
      inOrderTraversal(root->left);
      std::cout << root->data << std::endl;
      inOrderTraversal(root->right);
    }
  }

  BST *search(BST *root, int key) {
    if (!root || root->data == key)
      return root;

    if (root->data < key)
      return search(root->right, key);

    return search(root->left, key);
  }

  BST *insert(BST *root, int key) {

    if (!root)
      return new BST(key);

    if (key > root->data)
      root->right = insert(root->right, key);
    else
      root->left = insert(root->left, key);

    return root;
  }

  BST *deleteNode(BST *root, int key) {
    if (!root) {
      return root;
    }

    if (root->data > key) {
      root->left = deleteNode(root->left, key);
      return root;
    } else if (root->data < key) {
      root->right = deleteNode(root->right, key);
      return root;
    } else {
      if (!root->left && !root->right)
        return nullptr;
      else if (!root->left) {
        BST *temp = root->right;
        delete root;
        return temp;
      } else if (!root->right) {
        BST *temp = root->left;
        delete root;
        return temp;
      }

      BST *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }

    return root;
  }
};

