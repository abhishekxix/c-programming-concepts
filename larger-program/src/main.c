#include <stdio.h>

#include "./lib/other/other.h"
#include "./lib/some-other/some-other.h"

int main() {
  printf("%lf\n", perform_safe_division(10, 100));
  extern int some_global_variable_from_other_c;

  // extern int some_static_global_variable_from_other_c; // This is invalid

  printf(
      "External variable from other.c: %d\n", some_global_variable_from_other_c
  );

  invoke_some_other();
  print_static_global_variable_from_other_c();
  return 0;
}