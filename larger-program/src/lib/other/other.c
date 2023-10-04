#include "other.h"

#include <stdio.h>

/**
 * @brief Global variable accessible everywhere using extern
 *
 * This variable can be used anywhere in the program
 *
 */
int some_global_variable_from_other_c = 100;

/**
 * @brief Global variable only available in this module.
 */
static int some_static_global_variable_from_other_c = 200;

double perform_safe_division(double dividend, double divisor) {
  return divisor == 0 ? dividend : dividend / divisor;
}

void print_static_global_variable_from_other_c() {
  printf(
      "\nStatic global variable from other.c %d\n",
      some_static_global_variable_from_other_c
  );
}
