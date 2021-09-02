// This document contains an implementation of a binary min heap. It will
// contain all the normal functions one would expect to conduct on a min heap,
// as well as a function to initialize a sample min heap in the form of a
// priority queue.

// Definition of a heap (Wikipedia): a heap is a specialized tree-based data
// structure which is essentially an almost complete tree that satisfies the
// heap property (see below).

// A binary heap must satisfy two conditions
//  1. STRUCTURAL PROPERTY: the binary heap must be a full binary tree (meaning
//  all the levels of the tree are completely full (except maybe the last level,
//  which must be filled from left to right if it is not complete).
//  2. HEAP PROPERTY: the key stored in each node of the binary heap is either
//  "greater than or equal to" or "less than or equal to" the keys in the node's
//  children

// Binary heaps have the smallest possible height of log(n), where n is the
// total number of nodes in the heap.

// In a min heap, the keys of the parent nodes are ALWAYS greater than or equal
// to those of the children, and the lowest key is in the root node. For a
// priority queue, this means that the root node is always the lowest priority.

#include <iostream> // for basic input and output
#include <vector>   // to be able to use vectors

// even though a binary heap is a full binary tree, we don't normally use
// a binary tree to implement said heap. Instead, we store keys in an array (a
// vector in this case) and use their relative positions within that vector to
// represent parent-child relationships

// instead of explicitly defining a heap class, we are going to define a
// priority queue class, which is the most common implementation for a heap.
// This way it is easier to show the min heap in action.

// this class will contain functions to heapify_up and heapify_down (see below),
// functions to push and pop to the heap, a function to peek the top of the
// heap, and a utility function to check if the heap is empty.
class PriorityQueue {
private:
  std::vector<int> arr; // the vector that actually represent the heap

  // IMPORTANT NOTE:
  // because this is a heap and it satisfies the properties of a heap, there is
  // actually a consistent formula to find things like the parent, left child,
  // and right child of any given node.

  // this function will take the index of a node and return index of the parent
  // of the node. NOTE: don't call this function if the node at given index i is
  // already a root node, it will not work
  int parent(int i) {
    // the formula to get the parent node of any given node is floor((index of
    // node - 1)/2)
    return (i - 1) / 2;
  }

  // this function will take the index of a node and return the index of the
  // right child of the node
  int right(int i) {
    // the formula to get the right node of any given node is (2 times the
    // index) + 2
    return (2 * i) + 2;
  }

  // this function will take the index of a node and return the index of the
  // left child of the node
  int left(int i) {
    // the formula to get the left node of any given node is (2 times the
    // index) + 1
    return (2 * i) + 1;
  }

  // HEAPIFY OPERATIONS
  // heapify operations are extremely important in a heap. They are used to
  // correct a heap that does violates the properties of a heap (see above).
  // There are two ways to heapify a violating heap.

  // first we have heapify down. Heapify down is invoked if an element at index
  // i violates a heap property in with its two direct children. It converts the
  // binary tree, with its root at index i, and converts it into a heap by
  // moving said node down the tree (hence the name, heapify down). A heapify
  // down operation is normally used in the pop operation of a binary tree.

  // this function will take an index i, and turn the binary tree rooted at i
  // into a heap by moving the node at this index down the tree. The time
  // complexity of this function is O(log(n))
  void heapifyDown(int i) {
    // the strategy is to get the right and left child of the node at the given
    // index. Then compare the node at the the index with its left and right
    // children to find the smallest value. Finally, swap a child having smaller
    // value and call heapify down (recursively) on the child

    // declare a smallest variable, which starts at the current index, to hold
    // the smallest node in all the comparisons made
    int smallest = i;

    // get the left and right children
    int left = this->left(i);
    int right = this->right(i);

    // if the left node is discovered to be smaller than the current node, then
    // update the value of the smallest variable
    if (left < this->arr.size() && this->arr[left] < this->arr[i])
      smallest = left;

    // if the right node is discovered to be smaller than the current smallest,
    // then update the value of the smallest variable
    if (right < this->arr.size() && this->arr[right] < this->arr[smallest])
      smallest = right;

    // if the smallest doesn't turn out to be the node at index i itself, switch
    // the node at i with the child having the greater value. Then call
    // heapifyDown on the child
    if (smallest != i) {
      std::swap(this->arr[i], this->arr[smallest]);
      heapifyDown(smallest);
    }
  }

  // then we have heapify up. Heapify up is invoked if the parent of the
  // current node violates the heap property. It converts the binary tree into a
  // heap by moving the node up the tree (hence the name heapify up).

  // this function will take an index i, and turn the binary tree into a heap by
  // moving the node at index i up the tree. The time complexity of this
  // function is O(log(n)). A heapify up operation is normally used in the
  // push operation of a binary tree
  void heapifyUp(int i) {
    // the strategy is to check if the node at the given index i and its parent
    // violate the heap property. If they do, then swap the two, and then call
    // heapfiy up on the parent

    // if i exists and the node at index i's parent is greater than the node
    // itself
    if (i && this->arr[this->parent(i)] > this->arr[i]) {
      std::swap(this->arr[i], this->arr[this->parent(i)]); // swap the two nodes
      heapifyUp(this->parent(i)); // call heapify_up on the parent
    }
  }

public:
  // this is a utility function to check if the heap is empty
  bool isEmpty() { return this->arr.size() == 0; }

  // this is a utility function to check if the heap is empty
  int size() { return this->arr.size(); }

  // this function will take a key and push it into the heap. The time
  // complexity of this function, as mentioned in the README on priority queues,
  // is O(log(n))
  void push(int key) {
    // the strategy is to push a new element to the end of the vector, get the
    // index of it, and then call heapify_up on the new node (element) using the
    // index we got

    // push the new element into the array
    this->arr.push_back(key);

    int index = this->arr.size() - 1; // get the index of the new element
    heapifyUp(index);                 // call heapify up on the index
  }

  // this function will pop the element with the lowest priority in the heap
  // (which is at the root). As mentioned in the README on priority queues, the
  // time complexity of this operation is O(log(n))
  void pop() {
    // the strategy is to check if the heap is empty. If it is, we will return.
    // If it's not, then we're going to replace the the root of the heap with
    // the last element, pop back from the vector to remove the root, and then
    // heapify down the entire heap, starting from the 0th index (which is the
    // root node)

    if (this->isEmpty()) { // if the heap is empty
      std::cout << "Heap underflow. Refusing to pop." << std::endl;
      return;
    }

    this->arr[0] = this->arr.back(); // replace the root of of the heap with the
                                     // last element of the vector
    this->arr
        .pop_back(); // pop back from the array to get rid of the root element

    this->heapifyDown(0); // heapify down the whole heap (starting from index 0)
                          // to fix its structure
  }

  // this function will return the element in the heap with the lowest priority
  // (which will be the element at the root)
  int top() {
    // if the heap is empty, return
    if (this->isEmpty())
      exit(EXIT_FAILURE);

    // else return the first value in the vector
    return this->arr[0];
  }
};

// main function, which is just some driver code to test out the above
int main() {
  // create a new priority queue
  PriorityQueue *pq = new PriorityQueue();

  // NOTE: The element's value decides priority

  // push some elements to the heap
  pq->push(3);
  pq->push(2);
  pq->push(15);

  std::cout << "Size: " << pq->size() << std::endl;

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  // push some more elements to the heap
  pq->push(5);
  pq->push(4);
  pq->push(45);

  std::cout << "Size: " << pq->size() << std::endl;

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  // view the top and pop it
  std::cout << "Current top: " << pq->top() << std::endl;
  pq->pop();

  pq->pop(); // pop operation on an empty heap

  return 0;
}
