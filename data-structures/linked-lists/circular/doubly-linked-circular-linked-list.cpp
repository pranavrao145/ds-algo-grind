// This document contains an implementation of a doubly linked circular list. It
// will contain all the normal functions one would expect to conduct on a linked
// list, as well as a function to initialize a sample linked list.

// Definition of a linked list (Wikipedia): a linear collection of data
// elements whose order is not given by their physical placement in memory.
// Instead, each element points to the next.

// A doubly linked circular linked list is just like a singly linked circular
// linked list, except each node contains both a previous pointer and a next
// pointer

#include <iostream> // for basic input and output

// first we need a Node class, which will contain a key and a pointer
// to the next node and the previous node. We'll also give it a constructor
// to make life easier.
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node(int key) {
    this->data = key;
    this->prev = nullptr; // initially make the pointer a nullptr
    this->next = nullptr; // initially make the pointer a nullptr
  }
};

// we also need a DoublyLinkedList class, which will represent the list itself.
// the list will contain functions to add to the head of the list, after a
// given node of the list to the tail of the list, find a node in the list,
// and finally remove a node from the list. We will also include a utility
// function to print the data in the list.

class DoublyLinkedCircularLinkedList {
public:
  // the list needs a tail. Initialize to nullptr so we can check value later.
  // We're using tail because this is what we used in the singly linked
  // circular linked list, but you can do this with the head as well
  // because this is doubly linked
  Node *tail = nullptr;

  // this function will add to the head of the linked list. The time
  // complexity of this function is O(1) because it does a constant
  // amount of work
  void addToHead(Node *node) {
    // the strategy is to make this node point to the head,
    // and update the linked list's head attribute (tail->next) as the
    // current node. We also have to make this node's
    // prev the tail and update the old head's prev pointer
    // to this node.

    // check if the node we are trying to add actually exists
    // if not, return
    if (!node)
      return;

    // first we have to check if there's a tail or not
    // if not, we can just store it as the head
    if (!this->tail) {
      this->tail = node;       // set this node to be the tail
      this->tail->next = node; // make this point to itself as the head
      this->tail->prev = node; // also make the prev pointer point to itself
    } else {                   // if it is not a nullptr
      node->next = this->tail->next; // make this node point to the head
      node->prev = this->tail; // make the node's prev pointer point to the tail
      this->tail->next->prev =
          node; // make the current head's prev point to the new head
      this->tail->next =
          node; // make the tail point to this node (making it the new head)
    }
  }

  // this function will add the given node before another node in the
  // list, given a pointer to the node before which it must be inserted.
  // the time complexity of this function is O(1) because it does a constant
  // amount of work
  void addBeforeNode(Node *node, Node *placeBefore) {
    // the strategy is to make the new node's prev pointer point to the
    // node that the placeBefore node's prev pointer was initially pointing at,
    // and then make the placeBefore node's prev point to the new node. We also
    // have to change the next pointers accordingly. Specifically, the
    // next from the node we're inserting needs to be the one it was
    // placed before, and the next of the node before the node being
    // inserted's next needs to be the current node (see below for
    // a better explanation)

    // check if the node we are trying to add actually exists
    // if not, return
    if (!node)
      return;

    // if the given node to place after is nullptr, return
    if (!placeBefore)
      return;

    // make the current node's next the node we are placing before
    node->next = placeBefore;

    // point the new node's prev to the node the placeBefore one was pointing to
    node->prev = placeBefore->prev;

    // point the placeBefore node's prev to the current node
    placeBefore->prev = node;

    // unlike the regular DoublyLinkedList implementation, we don't
    // need to check for a nullptr here because we can safely assume
    // that the node has a previous (the list is circular)

    // make the next node's prev this node
    node->prev->next = node;
  }

  // this function will add the given node after another node in the
  // list, given a pointer to the node after which it must be inserted.
  // The time complexity of this function is O(1) because it does a constant
  // amount of work
  void addAfterNode(Node *node, Node *placeAfter) {
    // the strategy is to make the new node point to the node that the
    // placeAfter node was initially pointing at, and then make the placeAfter
    // node point to the new node. We also have to change the prev pointers
    // accordingly. Specifically, the prev from the node we're inserting needs
    // to be the one it was placed after, and the prev of the node after the
    // node being inserted's prev needs to be the current node (see below
    // for a better explanation)

    // check if the node we are trying to add actually exists
    // if not, return
    if (!node)
      return;

    // if the given node to place after is nullptr, return
    if (!placeAfter)
      return;

    // make the current node's prev the node we are placing after
    node->prev = placeAfter;

    // point the new node to the node the placeAfter one was pointing to
    node->next = placeAfter->next;

    // point the placeAfter node to the current node
    placeAfter->next = node;

    // unlike the regular DoublyLinkedList implementation, we don't
    // need to check for a nullptr here because we can safely assume
    // that the node has a next (the list is circular)

    // make the next node's prev this node
    node->next->prev = node;
  }

  // this function will add the node to the tail of the list.
  // The time complexity of this function is O(n) because it has to iterate
  // through the whole list of length n in order to find the tail.
  // Note: this could be optimizied to O(1) if you kept a tail pointer for
  // the linked list
  void addToTail(Node *node) {
    // the strategy is to iterate through the list until we find the tail,
    // and make the tail point to this node. Also, we have to make this
    // node's prev point to the old tail.

    // check if the node we are trying to add actually exists
    // if not, return
    if (!node)
      return;

    // first we have to check if there's a tail or not
    // if not, we can just store it as the head
    if (!this->tail) {
      this->tail = node; // make this the tail node

      // make the head this node, making it point to itself
      this->tail->next = node;

      // make this node's prev also point to itself
      this->tail->prev = node;
    } else {
      // make this node point to the next of the old tail
      node->next = this->tail->next;

      // make this node's prev point to the old tail
      node->prev = this->tail;

      // make the old head's prev point to this node
      this->tail->next->prev = node;

      // make the old tail point to this node
      this->tail->next = node;

      // make the new node the tail of this list
      this->tail = node;
    }
  }

  // this function will delete a node from the linked list, given a pointer
  // to the node that needs to be deleted. Unlike the SinglyLinkedList,
  // the delete function on this one will be O(1), because you don't
  // need to go through the list to find the previous node from the one
  // given.
  void deleteFromList(Node *node) {
    // the strategy is to take the next pointer of the prev of the node
    // given, and make it point to the node's next. Also change the
    // prev of the node's initial next to the node's initial prev.

    // this function assumes the memory for the node has been allocated
    // with new, so we will use the delete operator to get rid of it

    // check if the node we are trying to delete actually exists
    // if not, return
    if (!node)
      return;

    // if the node is the tail, the case is a bit special. We have to
    // delete the tail, but only after we make the prev the new tail,
    // and make the prev's next pointer the node after the old tail
    if (node == this->tail) {
      // make the new tail's next pointer the head
      this->tail->prev->next = this->tail->next;
      // make the prev of the head the new tail
      this->tail->next->prev = this->tail->prev;

      this->tail = this->tail->prev; // make the prev node the tail

      delete node; // free up space
    } else {
      // if the node is not the head, then we can carry on as usual

      // make the prev's next point to the node's next
      node->prev->next = node->next;

      // unlike the regular DoublyLinkedList implementation, we don't
      // need to check for a nullptr here because we can safely assume
      // that the node has a next (the list is circular)

      // make the node's next's prev pointer point to the node before
      // the initial node
      node->next->prev = node->prev;

      delete node; // free up space
    }
  }

  // this function will go through the list and find the node with
  // the data specified. When it is found, it will return a pointer to
  // the node that contains that data. The time complexity of this is
  // O(n), since it may have to iterate through the whole list to find
  // the right node. If not found, it will return a nullptr
  Node *findNode(int data) {
    // the srategy is to iterate through the list, and return the pointer
    // of the node when the data of the current node matches the data
    // requested

    // set a temp pointer, init to the head, where we'll start
    Node *temp = this->tail->next;

    // we have to check if the head has the data, in which we case
    // we return automatically
    if (temp->data == data) {
      return temp;
    } else {
      // while temp is still a valid pointer, the current node does not
      // contain the correct data, and temp does not point to the
      // head of the list, iterate through the list
      while (temp && temp->data != data && temp->next != this->tail->next) {
        temp = temp->next; // set the temp to the next node
      }
    }

    // if the temp variable is the head (which we've already dealt with),
    // it means the node was not found, so return nullptr. Else, return
    // temp, which is the node we want
    return temp == this->tail->next ? nullptr : temp;
  }

  // this function is pretty self explanatory. It will simply go through
  // the list and print each value. This function has an O(n) time
  // complexity because it has to go through the list to print out the values
  void printList() {
    // the strategy is to go through the list one by one and print out
    // each value. We need to deal with the head specially to get a
    // valid terminating condition for our loop

    Node *temp = this->tail->next; // start at the head

    if (!temp) { // if temp is a nullptr
      std::cout << "No items in list" << std::endl;
      return;
    }

    // print out the head
    std::cout << temp->data << std::endl;
    temp = temp->next; // move on to the next node

    // while temp actually exists and it's not the head
    while (temp && temp != this->tail->next) {
      std::cout << temp->data << std::endl; // print out the point
      temp = temp->next;                    // move on to the next node
    }
  }
};

int main(void) {
  // make 4 sample nodes to test out the linked list with
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);

  // creating a singly linked list object
  DoublyLinkedCircularLinkedList list;

  // some random test cases
  list.addToHead(node1);            // insert a node at head
  list.addToHead(nullptr);          // insert a nullptr at head
  list.addToTail(node2);            // insert node at tail
  list.addAfterNode(node3, node2);  // insert node3 after node2
  list.addBeforeNode(node4, node3); // insert node4 before node3
  list.deleteFromList(
      list.findNode(3)); // delete node3 from list after finding it
  list.deleteFromList(list.findNode(
      4)); // attempt to delete a node with 4, but it's not in the list yet
  list.addToTail(node5); // add node4 to the list

  list.printList(); // print out the final list

  return 0;
}
