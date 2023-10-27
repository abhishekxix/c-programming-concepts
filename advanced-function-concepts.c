#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/**
 * Variadic functions
 *
 * Variadic functions are functions that have variable number of arguments.
 *
 * stdarg.h has routines implemented as macros that need to be used to implement
 * variadic funcitons.
 *  - va_list -> type of pointer to the list of args
 *  - va_start -> macro to copy the list of args to a va_list variable
 *  - va_arg -> macro to access the current argument and move the pointer to the
 *              next one
 *  - va_end -> macro to stop the process of reading the args and reset the
 *              pointer to NULL
 *  - va_copy -> macro to copy the argument list into another variable so that
 *               we can go through it multiple times.
 *
 * A variadic function have atleast one fixed arg.
 */
int sum_many_numbers(int argc, ...) {
  va_list args_list;
  va_list args_list_copy;

  va_copy(args_list_copy, args_list);

  // Pass in the parameter preceeding the start of the optional parameters.
  va_start(args_list, argc);

  int num_args = argc;

  int sum = 0;

  while (num_args--) {
    // pass in the args_list and the type of the current arg
    sum += va_arg(args_list, int);
  }

  va_end(args_list);

  return sum;
}

/**
 * A recursive function is a function that calls itself
 *
 * @return int
 */
unsigned long long factorial(unsigned long long n) {
  if (n == 0) return 1;

  return n * factorial(n - 1);
}

/**
 * An inline function is a hint to the compiler to perform some form of
 * optimization or substitute the code into the caller instead of going about
 * the usual function execution process. Compiler may choose to ignore this
 * entirely.
 *
 *
 * By declaring a function inline, you can direct GCC to make calls to that
 * function faster. One way GCC can achieve this is to integrate that function's
 * code into the code for its callers. This makes execution faster by
 * eliminating the function-call overhead; in addition, if any of the actual
 * argument values are constant, their known values may permit simplifications
 * at compile time so that not all of the inline function's code needs to be
 * included. The effect on code size is less predictable; object code may be
 * larger or smaller with function inlining, depending on the particular case.
 *
 * When an inline function is not static, then the compiler must assume that
 * there may be calls from other source files; since a global symbol can be
 * defined only once in any program, the function must not be defined in the
 * other source files, so the calls therein cannot be integrated. Therefore, a
 * non-static inline function is always compiled on its own in the usual
 * fashion.
 *
 * @return int
 */
inline static int sum(int a, int b) { return a + b; }

/**
 * A function with noreturn or _Noreturn specifier tells the compiler and the
 * programmer that this function does not return the control to the calling
 * function.
 *
 * If a function declared as noreturn breaks its promise, it lends itself to
 * undefined behavior.
 *
 * @return noreturn
 */
noreturn void some_non_returning_function() { exit(112); }

int main() {
  printf("\n%d\n", sum_many_numbers(5, 1, 2, 3, 4, 5));
  printf("\n%llu\n", factorial(15));

  return 0;
}