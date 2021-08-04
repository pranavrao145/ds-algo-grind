// This document contains an implementation of a circular linked list. It will
// contain all the normal functions one would expect to conduct on a linked
// list, as well as a function to initialize a sample linked list

// Definition of a linked list (Wikipedia): a linear collection of data
// elements whose order is not given by their physical placement in memory.
// Instead, each element points to the next.

// A circular linked list is exactly like a singly linked list, but instead of
// the last node pointing to null, it points to the head, achieving a circular
// shape. To easily conduct operations on this list, we will store a pointer
// to the tail node of the list, such that tail->next gives us the head
// Note that if there is only one node in the list, it points to itself.

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

// we also need a SinglyLinkedCircularLinkedList class, which will represent the list
// itself. the list will contain functions to add to the head of the list, after
// a given node of the list to the tail of the list, find a node in the list,
// and finally remove a node from the list. We will also include a utility
// function to print the data in the list.

class SinglyLinkedCircularLinkedList {
    public:
        // the list needs a tail. Initialize to nullptr so we can check value later.
        Node *tail = nullptr;

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
            // if not, we can just store it as the head and make it point to
            // itself

            if (!this->tail) { // if the tail doesn't exist (empty)
                this->tail = node;     // make the tail this node

                // make the head this node, making it point to itself
                this->tail->next = node;
            } else {                         // if it is not a nullptr
                node->next = this->tail->next; // point this node to the current head
                this->tail->next = node;       // point the tail to this node
            }
        }


        // this function will add the given node before another node in the
        // list, given a pointer to the node before which it must be inserted
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

            Node* temp = this->tail->next; // set a temp pointer and init with head

            // we have to check special cases if the node is the head or tail

            // if the head is the node, we need to point this node to the head
            // and the tail to this node
            if (temp && temp == placeBefore) { 
                node->next = this->tail->next; // points this node to head
                this->tail->next = node; // points tail to this node
            } else {
                // if it is not the first node, we can carry on as usual
                // We just need to make sure we don't go in an infinite loop
                // by breaking the find attempt when the next node is the head,
                // which we've already checked

                // while temp exists and placeBefore is not the next node, keep
                // iterating over the list
                while (temp && temp->next != placeBefore && temp->next != this->tail->next) {
                    temp = temp->next;
                }

                // if temp is not null, and is actually a node, then we move things
                // around to accomodate the new node
                if (temp) {
                    temp->next = node; // set the temp node's next to this node
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
            // the new node. No special checking is needed for the circular list
            // because if something is added after the tail, it automatically
            // becomes the new head

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
        // unlike the regular singly linked list, this only has a time
        // complexity of O(1) because we keep a pointer to the tail
        void addToTail(Node *node) {
            // the strategy is to make the tail point to the new node,
            // the new node point to the old tail's next. We also have
            // to make this node the new tail

            // check if the node we are trying to add actually exists
            // if not, return
            if (!node)
                return;

            // if the tail does not exist yet (list empty)
            if (!this->tail) {
                this->tail = node;     // make the tail this node

                // make the head this node, making it point to itself
                this->tail->next = node;
            } else {
                // make this node point to the next of the old tail
                node->next = this->tail->next; 

                // make the old tail point to this node
                this->tail->next = node;

                // make the new node the tail of this list
                this->tail = node;
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

            Node* temp = this->tail->next; // set a temp pointer, we'll need it later

            // check if the node we are trying to delete actually exists
            // if not, return
            if (!node)
                return;

            // if the list is empty, then return    
            if (!temp)
                return;

            // if the tail is the node we're looking for, set the tail to it's
            // next and delete the current tail
            if (temp == node) {
                this->tail->next = temp->next;
                delete temp;
            } else { 
                // if the head is not the right node, then we search for the node
                // right before the one we want to delete set it's pointer to 
                // the node after the one we want to delete, and then finally
                // delete the stored temp node

                // while the temp pointer is not null, and the next node is not
                // the one we're looking for. We also need to break if the next
                // node is the tail, because in that case, we need to do special 
                // things to assign a new tail
                while (temp && temp->next != node && temp->next != this->tail) {
                    // set the temp's pointer to the next node
                    temp = temp->next; 
                }

                // temp has a chance of being null if the list is empty. We're
                // going to be using it in a conditional, so we need to check
                if (temp) {
                    // if the temp's next pointer is the tail
                    if (temp->next == this->tail) { 
                        temp->next = this->tail->next; // regular unlinking
                        this->tail = temp; // set a new tail

                        delete node; // freeing space
                    } else { // if the temp's next pointer is not the tail 
                        temp->next = node->next; // unlinking the node from the list
                        delete node; // freeing up space where the node used to exist
                    }
                }

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

            // set a temp pointer, init to the head, where we'll start
            Node* temp = this->tail->next;

            // we have to check if the head has the data, in which we case 
            // we return automatically
            if (temp->data == data) {
                return temp;
            } else {
                // while temp is still a valid pointer, the current node does not
                // contain the correct data, and temp does not point to the 
                // head of the list, iterate through the list
                while (temp && temp->data != data && temp->next != this->tail->next){
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

            Node* temp = this->tail->next; // start at the head

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
                temp = temp->next; // move on to the next node
            }
        }
};

int main(void)
{
    // make 4 sample nodes to test out the linked list with
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // creating a singly linked list object
    SinglyLinkedCircularLinkedList list;

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
