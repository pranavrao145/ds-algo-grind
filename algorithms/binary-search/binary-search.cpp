// This document contains the implementation of the binary search algorithm

// Definition of binary search (Wikipedia): a binary search, AKA the
// half-interval search, logarithmic search, or binary chop, is a search
// algorithm which finds the position of a target value within a sorted
// collection of data.

// the binary search will search a sorted array by repeatedly dividing the
// search interval in half. The interval will begin covering the whjole array.
// If the value of the search key is less than that of the item in the middle of
// the interval, narrow down the search area to the lower half, else the upper
// have. Repeatedly check until the value is found or the interval is empty.

// In the worst case, a binary search algorithm runs in O(log(n)) time, because
// it makes O(log(n)) comparisons.

// Below is a recursive implementation of the binary search algorithm

#include <iostream> // basic input and output

// this function will take a pointer to an int array, an interval start
// (initially the array start) and an interval end (initially the array end). It
// also takes a value for which to search. If the value is found, it returns the
// location of the element. Else it returns -1

int binarySearch(int *arr, int start, int end, int val) {
  // the strategy is to compare val with the middle element. If x matches
  // with the middle elemnt, return the mid index. If x is greater than the
  // mid element, then recurse for the right half of the current interval.
  // Else recurse for the left. At the end, if nothing is found, return -1.

  // check if there's actually an element to search
  if (end >= start) {
    int mid =
        start + (end - start) /
                    2; // calculate the middle index given the current interval

    // if the element is present at the middle itself
    if (arr[mid] == val)
      return mid; // return the mid index as the location of the element

    // if the middle element is greater than the desired value
    if (arr[mid] > val)
      return binarySearch(arr, start, mid - 1,
                          val); // search everything below the mid

    // if the middle element is less than the desired value
    if (arr[mid] < val)
      return binarySearch(arr, mid + 1, end,
                          val); // search everything above the mid
  }

  // if all else fails and the algorithm was unable to find the value (or there
  // was nothing else to search), return -1
  return -1;
}

// main function, which is just driver code to test above function
int main() {
  int array[] = {2, 3, 4, 10, 40}; // a static array to test the function on
  int size = sizeof(array) / sizeof(array[0]); // finding the size of the array

  // run the binary search with one element that is in the array and one that is
  // not, and store the result.
  int result1 = binarySearch(array, 0, size - 1, 10);
  int result2 = binarySearch(array, 0, size - 1, 12);

  (result1 != -1) ? std::cout << "Element " << 10
                              << " found at index: " << result1 << std::endl
                  : std::cout << "Element " << result1 << " not found in array."
                              << std::endl;

  (result2 != -1)
      ? std::cout << "Element " << 12 << " found at index: " << result2
                  << std::endl
      : std::cout << "Element " << 12 << " not found in array." << std::endl;

  return 0;
}
