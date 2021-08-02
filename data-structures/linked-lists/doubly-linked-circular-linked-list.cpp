// This document contains an implementation of a doubly linked circular list. It will
// contain all the normal functions one would expect to conduct on a linked
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
                this->tail = node; // set this node to be the tail
                this->tail->next = node; // make this point to itself as the head
                this->tail->prev = node; // also make the prev pointer point to itself
            }
            else {                 // if it is not a nullptr
                node->next = this->tail->next; // make this node point to the head 
                node->prev = this->tail; // make the node's prev pointer point to the tail
                this->tail->next->prev = node; // make the current head's prev point to the new head
                this->tail->next = node; // make the tail point to this node (making it the new head)
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
};


