#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 100;
  const int num_2 = 200;
  printf("%d", num_2);

  // pointer to constant value
  const int *ptr = &num;

  // constant pointer to a value
  int *const qptr = &num;

  // constant pointer to a constant value
  const int *const rptr = &num;

  int *some_other_ptr = &num_2;

  // this will not do anything.
  *some_other_ptr = 102;

  printf("%d", num_2);

  int array[] = {1, 2, 3, 4, 5};

  // Address of the first element of the array
  printf("%p\n", array);

  /**
   * constant pointer to the end of array array + size_of_array - 1 will give
   * the pointer to the last element of the array.
   */
  int *const ptr_to_end_of_array = array + 4;

  /**
   * The following for loop is using a pointer to an array as an iterator, by
   * incrementing it by one on each iteration.
   */
  for (int *ptr_to_array = array; ptr_to_array <= ptr_to_end_of_array;
       ++ptr_to_array) {
    printf("%d ", *ptr_to_array);
  }
  printf("\n");

  /**
   * Some pointer arithmetic stuff:
   *  - pointer + integer = pointer
   *  - pointer - pointer = integer, given that both of the pointers are of the
   *    same type. It makes sense when we want to find out how many elements are
   *    there between two elements of an array or something similar.
   *  - Increment/Decrement of a pointer = pointer
   *  - Comparison of two pointers using ==, <, >, <=, >=
   */

  return EXIT_SUCCESS;
}