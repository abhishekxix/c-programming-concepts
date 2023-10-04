#include <stdio.h>

/**
 * The #define preprocessor directive.
 *
 * It is used to define macros. Sometimes, it is also used to define constants
 * in the program.
 *
 * #define statements are generally used at the top of the file, but it is not
 * necessary to do so.
 *
 * #define statements are generally grouped together and put in a header file so
 * that they can be shared across multiple source files.
 *
 * By convention #define names are defined only using
 * UPPERCASE_WITH_UNDERSCORES, but it is also not necessary.
 *
 * #define statements are basically telling the preprocessor to do a
 * search-replace operation.
 *
 * #define statements have special syntax
 *  - No semicolon at the end of the line
 *  - No assignment operator
 *
 * #define makes the code more readable, by making constants have names.
 * It also makes the code more portable if used to substitute machine dependent
 * values.
 *
 * The proceeding statement directs the preprocessor to search for
 * MAX_BUFFER_SIZE and put 100UL in place of that in the program.
 */
#define MAX_BUFFER_SIZE 100UL

/**
 * The typedef keyword
 *
 * typedef is used to provide an alias for an already existing type.
 *
 * typedef ExistingType NewTypeName;
 *
 * The preceeding statement will NewTypeName as an alias for ExistingType. This
 * is essentially a type definition.
 *
 * The compiler will still treat the new type as the original type. Therefore,
 * type-checking is done.
 *
 * The benefit to doing this is making the code more readable in certain
 * contexts. For instance, size_t is basically just unsigned long but it tells
 * us that the variable defined as size_t represents a size.
 *
 */
typedef int64_t my_64bit_integer;

int main() {
  /**
   * The preprocessor will turn the next statement into the following:
   *
   * printf("\n%lu\n", 100UL);
   */
  printf("\n%lu\n", MAX_BUFFER_SIZE);

  /**
   * my_integer is a long long
   */
  my_64bit_integer my_integer = 101010LL;

  printf("\n%lld\n", my_integer);

  return 0;
}