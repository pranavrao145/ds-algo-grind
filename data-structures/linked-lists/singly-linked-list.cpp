// This document contains an implementation of a singly linked list. It will
// contain all the normal functions one would expect to conduct on a linked
// list, as well as a function to initialize a sample linked list

// Definition of a linked list (Wikipedia): a linear collection of data
// elements whose order is not given by their physical placement in memory.
// Instead, each element points to the next.

// A singly linked list means that each node only points to the next. There
// is also a head node, which is simply the node from which you would start
// traversal (it leads to the next one, which leads to the next, and
// so on and so forth)

#include <iostream> // for basic input and output

// first we need a Node class, which will contain a key and a pointer
// to another node. We'll also give it a constructor to make life easier.
class Node {
    public:
        int data;
        Node *next;

        Node(int key) { 
            this->data = key;
            this->next = nullptr; // initially make the pointer a nullptr
        }
};

// we also need a SinglyLinkedList class, which will represent the list itself.
// the list will contain functions to add to the head of the list, after a
// given node of the list to the tail of the list, find a node in the list, 
// and finally remove a node from the list. We will also include a utility
// function to print the data in the list.

class SinglyLinkedList {
    public:
        // the list needs a head. Initialize to nullptr so we can check value later.
        Node *head = nullptr;

        // this function will add to the head of the linked list. The time
        // complexity of this function is O(1) because it does a constant
        // amount of work
        void addToHead(Node *node) {
            // the strategy is to make this node point to the head,
            // and update the linked list's head attribute as the current node

            // check if the node we are trying to add actually exists
            // if not, return
            if (!node)
                return;

            // first we have to check if there's a head or not
            // if not, we can just store it as the head
            if (!this->head)
                this->head = node;
            else {                 // if it is not a nullptr
                node->next = this->head; // point this node to the head
                this->head = node;  // update the head of the list
            }
        }
        
        // this function will add the given node before another node in the
        // list, given a pointer to the node before which it must be inserted.
        // The time complexity of this function is O(n) because it must loop
        // through the list to figure out what node was initially before placeBefore
        void addBeforeNode(Node *node, Node *placeBefore) {
            // the strategy is to iterate through the list to find the node
            // one before the placeBefore node. Then, make that node point to the
            // new node and make this node point to the placeBefore node

            // check if the node we are trying to add actually exists
            // if not, return
            if (!node)
                return;

            // if the given node to place after is nullptr, return
            if (!placeBefore)
                return;

            Node* temp = this->head; // set a temp pointer, we'll need it later

            // if the placeBefore is the first node, things are a bit different.
            // We have to insert at the head in this case
            if (temp && temp == placeBefore) { 
                node->next = placeBefore; // point node to placeBefore
                this->head = node; // make node the head of the list
            } else {
                // if it is not the first node, we can carry on as usual

                // while temp exists and placeBefore is not the next node, keep
                // iterating over the list
                while (temp && temp->next != placeBefore) {
                    temp = temp->next;
                }

                // if temp is not null, and is actually a node
                if (temp) {
                    temp->next = node; // set temp node's next to this node
                    node->next = placeBefore; // set this node's next to placeBefore
                }
            }

        }

        // this function will add the given node after another node in the
        // list, given a pointer to the node after which it must be inserted.
        // The time complexity of this function is O(1) because it does a constant
        // amount of work
        void addAfterNode(Node *node, Node *placeAfter) {
            // the strategy is to make the new node point to the node that the old
            // node was initially pointing at, and then make the old node point to
            // the new node
            
            // check if the node we are trying to add actually exists
            // if not, return
            if (!node)
                return;

            // if the given node to place after is nullptr, return
            if (!placeAfter)
                return;

            // point the new node to the node the old one was pointing to
            node->next = placeAfter->next; 

            // point the  old node to the current node
            placeAfter->next = node; 
        }

        // this function will add the node to the tail of the list.
        // The time complexity of this function is O(n) because it has to iterate
        // through the whole list of length n in order to find the tail. 
        // Note: this could be optimizied to O(1) if you kept a tail pointer for
        // the linked list
        void addToTail(Node *node) {
            // the strategy is to iterate through the list until we find the tail,
            // and make the tail point to this node

            // check if the node we are trying to add actually exists
            // if not, return
            if (!node)
                return;

            // first we have to check if there's a head or not
            // if not, we can just store it as the head
            if (!this->head)
                this->head = node;
            else {
                // make a pointer last to hold the last discovered node
                Node *last = this->head; 

                // while the last discovered node still has a next
                while (last->next) { 
                    // update the last discovered node to the next one
                    last = last->next; 
                }

                // change the next of the last node
                last->next = node;
            }
        }

        // this function will delete a node from the linked list, given a pointer
        // to the node that needs to be deleted. The time complexity of this function
        // is O(n) because it needs to go through the list to find the previous node
        // from the one to delete
        void deleteFromList(Node *node) {
            // the strategy is to go through the list, and if a node's next
            // matches with the node given, make that node point to the given
            // node's next, and then delete the given node

            // this function assumes the memory for the node has been allocated 
            // with new, so we will use the delete operator to get rid of it

            Node* temp = this->head; // set a temp pointer, we'll need it later

            // check if the node we are trying to delete actually exists
            // if not, return
            if (!node)
                return;

            // if the list is empty, then return    
            if (!temp)
                return;

            // if the head is the node we're looking for, set the head to it's
            // next and delete the current head
            if (temp == node) {
                this->head = temp->next;
                delete temp;
            } else { 
                // if the head is not the right node, then we search for the node
                // right before the one we want to delete set it's pointer to 
                // the node after the one we want to delete, and then finally
                // delete the stored temp node

                // while the temp pointer is not null, and the next node is not
                // the one we're looking for 
                while (temp && temp->next != node) {
                    // set the temp's pointer to the next node
                    temp = temp->next; 
                }

                // now temp stores the pointer to the node right before the 
                // one we want to delete
                
                // we don't need to check if temp exists here because worst case
                // it is the end of the list, and we are setting that pointer
                // (which is nullptr) to nullptr again (beause node->next is
                // initialized as nulltpr)
                temp->next = node->next; // unlinking the node from the list

                delete node; // freeing up space where the node used to exist
            }
        }

        // this function will go through the list and find the node with 
        // the data specified. When it is found, it will return a pointer to
        // the node that contains that data. The time complexity of this is
        // O(n), since it may have to iterate through the whole list to find
        // the right node. If not found, it will return a nullptr
        Node* findNode(int data) {
            // the srategy is to iterate through the list, and return the pointer
            // of the node when the data of the current node matches the data
            // requested

            Node* temp = this->head; // set a temp pointer, we'll need it later

            // while temp is still a valid pointer and the current node does not
            // contain the correct data, iterate through the list
            while (temp && temp->data != data) {
                temp = temp->next; // set the temp to the next node
            }

            // return temp, which will either be the node requested or a nullptr
            // if the node was not found
            return temp;
        }

        // this function is pretty self explanatory. It will simply go through
        // the list and print each value. This function has an O(n) time
        // complexity because it has to go through the list to print out the values
        void printList() { 
            // the strategy is to go through the list one by one and print out
            // each value

            Node* temp = this->head; // start at the head
            
            if (!temp) { // if temp is a nullptr
                std::cout << "No items in list" << std::endl;
                return;
            }
            
            // while temp actually exists
            while (temp) {
                std::cout << temp->data << std::endl; // print out the point
                temp = temp->next; // move on to the next node
            }
        }
};


// main function, which is just some driver code to test out the above
int main(void)
{
    // make 4 sample nodes to test out the linked list with
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // creating a singly linked list object
    SinglyLinkedList list;

    // some random test cases
    list.addToHead(node1); // insert a node at head
    list.addToHead(nullptr); // insert a nullptr at head
    list.addToTail(node2); // insert node at tail
    list.addAfterNode(node3, node2); // insert node3 after node2
    list.addBeforeNode(node4, node3); // insert node4 before node3
    list.deleteFromList(list.findNode(3)); // delete node3 from list after finding it
    list.deleteFromList(list.findNode(4)); // attempt to delete a node with 4, but it's not in the list yet
    list.addToTail(node5); // add node4 to the list

    list.printList(); // print out the final list

    return 0;
}
