#include <stdio.h>

/**
 * Storage classes are used to describe the features of a variable/function
 * including the following information:
 *  - scope
 *  - visibility
 *  - life-time
 *
 * Types of storage classes:
 *  - auto
 *      - default.
 *      - Variables declared with auto storage class only exist as long as the
 *        scope they are in exists. All local variables are auto storage class
 *        variables. It is seldom used for sake of interoperability with C++
 *      - auto uses the principle of least privilege.
 *  - extern
 *      - Tells us that the variable is defined somewhere else.
 *      - An extern variable must be a global variable with a legal value where
 *        it is defined for it to be usable anywhere else.
 *      - Main purpose is to make global variables shareable between multiple
 *        files.
 *      - If we declare a function as extern, it can be used anywhere else in
 *        the program without defining it in a header file and importing that.
 *  - static
 *    - If applied to a local variable, the value of that variable persists for
 *      the life-time of the program. This means that the value persists between
 *      function calls and the variable is not defined again and again.
 *        - The initial value of the variable must be a simple constant or a
 *          constant expression.
 *        - The initial value for static variables is 0 unlike auto variables.
 *        - static variables are allocated memory on the heap, not on the stack.
 *    - If applied to a global variable, that global variable can not be used in
 *      other modules with the extern keyword. The global variable stays global
 *      to the module in which it is defined only.
 *    - If applied to a function, that function can only be used in that
 *      particular file.
 *  - register
 *    - A suggestion to the compiler to store the variable in the register.
 *    - It is a performance consideration. It's not necessary that the compiler
 *      will do it.
 *    - lifetime is similar to auto variables.
 *    - Address of a register variable can not be accessed as it is not in the
 *      memory.
 */

/**
 * @brief Returns the incremented value of the counter.
 *
 * @return int
 */
int static_counter() {
  static int counter = 0;
  return ++counter;
}

int main() {
  for (int i = 0; i < 5; i++) {
    printf("%d", static_counter());
    if (i != 4)
      printf(", ");
    else
      printf("\n");
  }

  return 0;
}