#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.

// NOTES: 
// Arrays:

// What is an array?
// And array is a sequences of elements of the same type stored in a contiguous block of memory.

// 1. Each element must be the same type. 
// 2. They must be in a contiguous block of memory.

// How do you declare an array?
// 1. Determine how big the array needs to be
// 2. Request a block of memory that will fit the array
// 3. Receive the memory address of the reserved block
// 4. Write your values into the array

// Declare the array: [2, 3, 4, 5]
// 1. Determine how big the array needs to be
// 	- An integer is 4 bytes, so the array needs to be 16 bytes
// 2. Request a block of memory that will fit the array
// 	- Request 16 bytes of memory from the computer
// 3.  Receive the memory address of the reserved block 
// 	- Receive an address to the start of 16 bytes of reserved memory
// 4. Write your values into the array
// 	- Write the values of 2, 3, 4, 5 into the array 

// 10 in binary is 2
// 11 is 3
// 100 is 4
// 101 is 5

// Arrays are the most time and space efficient data structures that we have.

// What is a Python List?
// Python lists are arrays with a lot of built-in functionality. Basically arrays.

// How do you add an element to the end of an array?
// 1. Take the size of your current array and increase it by one element.
// 2. Request a block of memory of the new size. 
// 3. Copy each element from the old space to the new space one at a time.
// 4. Free the memory from the old array.
// 	- This is an O(n) operation! 

// How does Python add an element to the end of a list?
// 	- Python will allocate a few empty spaces each time the array grows.
// 	- Each time it grows, it allocates a bit more extra space than the previous
// 	- Adding an element to the end of a list is usually O(1) but sometimes O(n)
// 	- On average, can be considered O(1)

// How does Python add an element to the beginning of a list? 
// 1. Check is there's any empty space at the end of the array
// 2. If not:
// 	- Allocate a new array, place the first element and copy over the rest
// 	- Then free memory from the old array.
// 3. If so: 
// 	- Starting from the back, move EACH element tot he right one space
// 	- Place the new element in the first position
// - This is an 0(n) operation no matter what!


typedef struct Array {
  int capacity;  // How many elements can this array hold?
  int count;  // How many states does the array currently hold?
  char **elements;  // The string elements contained in the array
} Array;


/************************************
 *
 *   CREATE, DESTROY, RESIZE FUNCTIONS
 *
 ************************************/

/*****
 * Allocate memory for a new array
 *****/
Array *create_array (int capacity) {
  // Allocate memory for the Array struct

  // Set initial values for capacity and count

  // Allocate memory for elements

}


/*****
 * Free memory for an array and all of its stored elements
 *****/
void destroy_array(Array *arr) {

  // Free all elements

  // Free array

}

/*****
 * Create a new elements array with double capacity and copy elements
 * from old to new
 *****/
void resize_array(Array *arr) {

  // Create a new element storage with double capacity

  // Copy elements into the new storage

  // Free the old elements array (but NOT the strings they point to)

  // Update the elements and capacity to new values

}



/************************************
 *
 *   ARRAY FUNCTIONS
 *
 ************************************/

/*****
 * Return the element in the array at the given index.
 *
 * Throw an error if the index is out of range.
 *****/
char *arr_read(Array *arr, int index) {

  // Throw an error if the index is greater or equal to than the current count

  // Otherwise, return the element at the given index
}


/*****
 * Insert an element to the array at the given index
 *
 * Store the VALUE of the given string, not the REFERENCE
 *****/
void arr_insert(Array *arr, char *element, int index) {

  // Throw an error if the index is greater than the current count

  // Resize the array if the number of elements is over capacity

  // Move every element after the insert index to the right one position

  // Copy the element (hint: use `strdup()`) and add it to the array

  // Increment count by 1

}

/*****
 * Append an element to the end of the array
 *****/
void arr_append(Array *arr, char *element) {

  // Resize the array if the number of elements is over capacity
  // or throw an error if resize isn't implemented yet.

  // Copy the element and add it to the end of the array

  // Increment count by 1

}

/*****
 * Remove the first occurence of the given element from the array,
 * then shift every element after that occurence to the left one slot.
 *
 * Throw an error if the value is not found.
 *****/
void arr_remove(Array *arr, char *element) {

  // Search for the first occurence of the element and remove it.
  // Don't forget to free its memory!

  // Shift over every element after the removed element to the left one position

  // Decrement count by 1

}


/*****
 * Utility function to print an array.
 *****/
void arr_print(Array *arr) {
  printf("[");
  for (int i = 0 ; i < arr->count ; i++) {
    printf("%s", arr->elements[i]);
    if (i != arr->count - 1) {
      printf(",");
    }
  }
  printf("]\n");
}


#ifndef TESTING
int main(void)
{

  Array *arr = create_array(1);

  arr_insert(arr, "STRING1", 0);
  arr_append(arr, "STRING4");
  arr_insert(arr, "STRING2", 0);
  arr_insert(arr, "STRING3", 1);
  arr_print(arr);
  arr_remove(arr, "STRING3");
  arr_print(arr);

  destroy_array(arr);

  return 0;
}
#endif
