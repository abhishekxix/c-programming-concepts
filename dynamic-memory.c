#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_elements = 10;
  /**
   * calloc allocates given number of memory blocks of a certain size. It also
   * initializes all of them to 0
   *
   * -  The return value is NULL if there is not enough storage, or if num or
   *    size is 0.
   */
  int *dynamic_array = (int *)calloc(10, sizeof(int));
  // ! don't forget to free the memory.
  free(dynamic_array);

  /**
   * malloc allocates given number of bytes of memory  of a certain size. It
   * does not initialize the memory
   *
   * -  The return value is NULL if not enough storage is available, or if size
   * was specified as zero.
   */
  dynamic_array = (int *)malloc(number_of_elements * sizeof(int));

  /**
   * realloc resizes the memory allocated to a given pointer. If the pointer is
   * not NULL, the pointer should have memory allocated to it via malloc,
   * calloc, or realloc, and must not have been freed.
   *
   * realloc also preserves the contents of the original memory pointed to by
   * the pointer passed in.
   *
   * If realloc assigns a new memory block, the old memory block is free by it
   * automatically.
   *
   * -  If size is 0, the realloc() function returns NULL. If there is not
   *    enough storage to expand the block to the given size, the original block
   *    is unchanged and the realloc() function returns NULL.
   */
  dynamic_array = (int *)realloc(dynamic_array, ++number_of_elements);

  int *tmp = dynamic_array;
  int *end_of_array = dynamic_array + number_of_elements - 1;

  while (tmp++ <= end_of_array) {
    printf("%d ", *tmp);
  }

  // ! don't forget to free the memory.
  free(dynamic_array);

  int *dma = (int *)calloc(10 /* number of elements */, sizeof(int));

  int *dma_reallocated = (int *)realloc(dma, 200 * sizeof(int));

  if (dma == dma_reallocated) {
    printf("dma == dma_reallocated ✅");
  } else {
    printf("dma == dma_reallocated ❌");
  }

  free(dma_reallocated);

  return EXIT_SUCCESS;
}