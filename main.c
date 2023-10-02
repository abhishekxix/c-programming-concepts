#include <stdio.h>
#include <stdlib.h>

int main() {
  // int nums[5] = {1, 2, 3, 4, 5};
  int *nums = (int *)calloc(5, sizeof(int));

  for (int i = 0; i < 5; i++) {
    nums[i] = i;
  }

  // nums[2];  // value at nums + 2
  // *(nums + 3)
  // *(nums + 0) -> nums[0]

  // printf("%d", *(nums + 0));

  // for (int i = 0; i < 5; i++) {
  //   printf("%d", *(nums + i));
  // }

  // int matrix[5][3];
  int **matrix =
      (int **)calloc(5, sizeof(int *));  // allocating a array of pointers

  for (int i = 0; i < 5; i++) {
    *(matrix + i) =
        (int *)calloc(3, sizeof(int));  // allocating an array of integers to
                                        // each pointer in the array of pointers
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = i + j;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++) {
    free(*(matrix + i)
    );  // need to free the memory of each of the arrays inside the matrix.
  }

  free(matrix);  // need to free the  memory of the matrix that stores the
                 // pointers to other arrays.

  return 0;
}