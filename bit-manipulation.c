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

  /**
   * Bit fields.
   *
   * A bit field allows us to specify the number of bits in which an integer
   * member of a struct is stored.
   *
   * Bit fields use a special syntax in structure definition that allow us to
   * define a field of bits and assign a name to it. We should use explicit
   * declarations for signed and unsigned integers to avoid problems with the
   * hardware. C99 and C11 additionally allow type _Bool bit fields.
   *
   * Bit fields enable better memory utilization as we only use as many bits as
   * we need as opposed to the size of an integer.
   *
   * We can easily manipulate or retrieve the values inside a bit field without
   * masking or shifting.
   *
   * A bit field is declared by following an unsigned int member of a struct
   * with a colon (:) and an integer constant which represents the width of the
   * bit field. 0 <= width_constant <= total number of bits to store an int on
   * the system.
   *
   * It is possible to define an unnamed bit field that is used as a padding for
   * the struct.
   *
   * An unnamed bit field with 0 width is used to align the next bit field on a
   * new storage unit boundary.
   */
  struct Packed_Data {
    unsigned int : 3;  // skip the first 3 bits
    unsigned int f1 : 1;
    unsigned int f2 : 1;
    unsigned int f3 : 1;
    unsigned int type : 8;
    unsigned int index : 18;
  } packed_data;

  // The individual values can be accessed inside the field.
  packed_data.type = 5;

  return 0;
}