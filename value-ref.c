#include <stdio.h>

void swap(int first, int second) {
  int temp = first;
  first = second;
  second = temp;
  printf("in swap: first = %d, second = %d\n", first, second);
}

void swap_by_ptr(int* first, int* second) {
  int temp = *first;
  *first = *second;
  *second = temp;

  printf("in swap by pointer: first = %d, second = %d\n", *first, *second);
}

int main() {
  int a = 10;
  int b = 20;

  swap(a, b);  // values of a and b will be sent to swap. This means that the
               // manipulations to these values in swap will not reflect in
               // changes to the values in main.
  printf("in main after normal swap: a = %d, b = %d\n", a, b);

  int* aptr = &a;
  int* bptr = &b;
  swap_by_ptr(
      aptr, bptr
  );  // values of aptr and bptr i.e. the addresses of a
      // and b respectively will be sent to swap_by_ptr. This means that the
      // memory where a and b are stored can be manipulated in this function.
  printf("in main after swap through pointer: a = %d, b = %d\n", a, b);

  return 0;
}