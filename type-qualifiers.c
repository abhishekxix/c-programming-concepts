#include <stdio.h>

int main() {
  /**
   * Type qualifiers give compiler more information about the intended use of a
   * variable. This makes the compiler apply certain rules on the variables.
   *
   * Following are three type qualifiers in C.
   *  - const
   *  - volatile
   *  - restrict
   */

  /**
   * const describes that the variable is a constant and will not be changed by
   * the program.
   *
   * This allows for the variable to be placed in Read-Only Memory and be more
   * efficient to access.
   *
   * If we try to modify a constant, we will get an error.
   *
   */
  const double pi = 3.141592654;

  /**
   * cannot assign to variable 'pi' with const-qualified type 'const
   double'
   *
   */
  // pi = 4.3;

  int some_number = 10;
  int some_other_number = 20;

  /**
   * Pointer to a constant value
   *
   */
  const int *pointer_to_constant_int = &some_number;

  /**
   * expression must be a modifiable lvalue
   *
   */
  // *pointer_to_constant_int = 100;

  /**
   * This is legal
   *
   */
  // pointer_to_constant_int = &some_other_number;

  int *const constant_pointer_to_int = &some_other_number;

  /**
   * This is legal
   *
   */
  // *constant_pointer_to_int = 200;

  /**
   * cannot assign to variable 'constant_pointer_to_int' with const-qualified
   * type 'int *const'
   *
   */
  // constant_pointer_to_int = &some_number;

  const int *const constant_pointer_to_constant_value = &some_number;

  /**
   * expression must be a modifiable lvalue
   *
   */
  // *constant_pointer_to_constant_value = 2394023;

  /**
   * cannot assign to variable 'constant_pointer_to_constant_value' with
   * const-qualified type 'const int *const'
   *
   */
  // constant_pointer_to_constant_value = &some_other_number;

  /**
   * volatile describes that a variable's value might change unexpectedly. It is
   * a way of telling the compiler to not apply optimizations on that variable
   * because it might change quite frequently.
   *
   * It suppresses the optimizations by the compiler and the value is always
   * only read from the memory and not the registers, because the value might
   * change even if it is not changed anywhere in the source code.
   *
   * It is mostly used in real-time or resource-constrained systems.
   *
   * Only three types of variables should use volatile:
   *  - memory-mapped peripheral registers.
   *  - global variables (non stack variables) modified by an interrupt service
   *    routine.
   *  - global variables accessed by multiple tasks within a multi-threaded
   *    application.
   */
  volatile int volatile_value;

  /**
   * A pointer to a volatile value
   *
   */
  volatile int *ptr_to_volatile_value;

  /**
   * A volatile pointer to an integer.
   *
   * This pointer might get unexpectedly reassigned.
   *
   */
  int *volatile volatile_ptr_to_value;

  /**
   * A volatile pointer to a volatile integer.
   *
   * The value pointed to by the pointer might change unexpectedly, and even the
   * value of pointer (i.e the address it is pointing to) might change
   * unexpectedly.
   *
   */
  volatile int *volatile volatile_ptr_to_volatile_value;

  /**
   * const and volatile can be used together.
   *
   * Might be changed by some other entity, but we are not going to change it.
   * So don't cache the values or apply optimizations.
   */
  volatile const int *hardware_clock_reference;

  {
    /**
     * restrict type qualifier is an optimization hint to the compiler.
     *
     * It hints the compiler that the pointer is the only reference to the
     * underlying data. This means that the value can be cached safely.
     *
     * Without the restrict keyword, the compiler assumes that the value might
     * have changed between two uses of the pointer.
     *
     * The statements below describe that pointer and second_pointer while in
     * the same scope will not access the same value.
     *
     * Even if they point to some array values, they should do it in a mutually
     * exclusive fashion.
     *
     * There are no errors for violation of this rule, but the behaviour of the
     * program might be undefined.
     */
    int a = 0;
    int b = 10;
    int *restrict pointer = &a;
    int *restrict second_pointer = &b;
    // second_pointer = pointer; // this will not throw an error but may produce
    // undefined results.}
  }

  return 0;
}