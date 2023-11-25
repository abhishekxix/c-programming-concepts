#include <stdio.h>
#include <string.h>

#include "my-custom-static-lib/my-custom-static-lib.h"

int main() {
  char my_string[100] = "This is my string that is very awesome.";
  const char* delimiter = " ";

  char* current_token = NULL;

  current_token = strtok(my_string, delimiter);

  while (current_token) {
    printf("%s\n", current_token);
    current_token = strtok(NULL, delimiter);
  }
  printf("done\n");

  printf("%lu", sizeof(long));

  print_my_custom_static_lib();

  return 0;
}