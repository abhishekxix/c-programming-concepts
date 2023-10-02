#include <stdio.h>
#include <string.h>

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

  return 0;
}