#include <stdio.h>

int main() {
  /**
   * Bitwise operations
   *
   * - Faster than arithmetic operations.
   * - Operate on bits in integer values including chars.
   * - Don't work with floating point values.
   *
   */

  /**
   * Logical operators.
   *  - Bitwise AND '&'
   *  - Bitwise OR '|'
   *  - Bitwise XOR '^'
   *  - Bitwise Complement '~'. It is a 2's complement
   */
  int num1 = 4;   // arbitrary number
  int num2 = 16;  // arbitrary number

  struct {
    int and;
    int or ;
    int xor ;
    int complement;
    int left_shift;
    int right_shift;
  } result;

  result.and = num1 & num2;
  result.or = num1 | num2;
  result.xor = num1 ^ num2;
  result.complement = ~num1;

  /**
   * Shift operators
   *
   * - << Left shift - Vacated bits are set to 0
   * - >> Right shift - Vacated bits are set to 0 for unsigned left operand, and
   *      to the signed bit for signed operand.
   */
  int num = 4;

  result.left_shift = num << 2;

  result.right_shift = num >> 1;

  printf(
      "\nnum = %d, num1 = %d, num2 = %d\nnum1 & num2 = %d\nnum1 | num2 = "
      "%d\nnum1 ^ num2 "
      "= %d\n~num1 = %d\nnum << 2 = %d\nnum >> 1 = %d\n",
      num, num1, num2, result.and, result.or, result.xor, result.complement,
      result.left_shift, result.right_shift
  );

  return 0;
}