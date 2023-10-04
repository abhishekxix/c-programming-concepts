#include "some-other.h"

#include <stdio.h>

extern int some_global_variable_from_other_c;

void invoke_some_other() {
  printf(
      "External variable in some-other.c %d", some_global_variable_from_other_c
  );
}