#include <stdio.h>

int main() {
  int count = 0;
  // labelled code.
first_statement:
  printf("\nThe first statement\n");
  count++;

  /**
   * goto
   *
   * goto statement is used to do unconditional branching and jump to a
   * labelled part of code.
   *
   * `break` and `continue` are specilized forms of goto
   *
   */
  if (count < 2) {
    goto first_statement;
  }

  /**
   * null statement
   *
   * null statment is a an expression statement with the expression missing.
   *
   * This is sort of a syntactical shortcut to omit certain code.
   *
   * An example could be some code executing in the parentheses of the while
   * loop.
   *
   * while(some_expression_that_also_does_the_job);
   */

  /**
   * The comma operator
   *
   * lowest precedence
   *
   * It is a binary operator that discards the result of the left operand and
   * returns the type and value of the second operand. The operands can be
   * expressions.
   *
   */

  return 0;
}