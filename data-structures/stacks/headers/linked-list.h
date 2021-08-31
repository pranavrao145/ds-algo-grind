#include <iostream>

class Node {
public:
  int data;
  Node *next;

  Node(int key) {
    this->data = key;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
public:
  Node *head = nullptr;

  void addToHead(Node *node) {
    if (!node)
      return;

    if (!this->head)
      this->head = node;
    else {
      node->next = this->head;
      this->head = node;
    }
  }

  void addBeforeNode(Node *node, Node *placeBefore) {
    if (!node)
      return;

    if (!placeBefore)
      return;

    Node *temp = this->head;

    if (temp && temp == placeBefore) {
      node->next = placeBefore;
      this->head = node;
    } else {
      while (temp && temp->next != placeBefore) {
        temp = temp->next;
      }

      if (temp) {
        temp->next = node;
        node->next = placeBefore;
      }
    }
  }

  void addAfterNode(Node *node, Node *placeAfter) {

    if (!node)
      return;

    if (!placeAfter)
      return;

    node->next = placeAfter->next;

    placeAfter->next = node;
  }

  void addToTail(Node *node) {
    if (!node)
      return;

    if (!this->head)
      this->head = node;
    else {
      Node *last = this->head;

      while (last->next) {
        last = last->next;
      }

      last->next = node;
    }
  }

  void deleteFromList(Node *node) {
    Node *temp = this->head;

    if (!node)
      return;

    if (!temp)
      return;

    if (temp == node) {
      this->head = temp->next;
      delete temp;
    } else {
      while (temp && temp->next != node) {
        temp = temp->next;
      }

      temp->next = node->next;

      delete node;
    }
  }

  Node *findNode(int data) {
    Node *temp = this->head;

    while (temp && temp->data != data) {
      temp = temp->next;
    }

    return temp;
  }

  void printList() {
    Node *temp = this->head;

    if (!temp) {
      std::cout << "No items in list" << std::endl;
      return;
    }

    while (temp) {
      std::cout << temp->data << std::endl;
      temp = temp->next;
    }
  }
};
