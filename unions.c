#include <stdbool.h>
#include <stdio.h>

/**
 * In C, a union is a user-defined data type that allows many different data
 * types to be stored in the same memory region. A union can have numerous
 * members, but only one of them can occupy the memory at any one moment. Unions
 * allow developers to optimize memory usage while declaring variables.
 *
 * A Union is created with enought space for the largest member.
 *
 * If we assign a value to one of the members, the values of other members will
 * be wiped out.
 */
union Physical_Attribute {
  double weight;
  short int size;
  bool is_brittle;
  unsigned long long number_of_atoms;
};

enum TYPES {
  INTEGER,
  FLOAT,
  DOUBLE,
  LONG,
  LONG_LONG,
};

struct Complex_Type {
  const char* name;
  enum TYPES type;

  /**
   * Anonymous union
   *
   * We can access these directly as members of Complex_Type, but only one at a
   * time.
   */
  union {
    int i;
    float f;
    double d;
    long l;
    long long ll;
  };
};

int main() {
  union Physical_Attribute attr = {.size = 200};
  union Physical_Attribute* attr_ptr;
  struct Complex_Type ct = {.name = "mytype", .type = INTEGER, .i = 20};

  printf("\n%lu\n", sizeof(attr));
  printf("\n%lu\n", sizeof(attr_ptr));
  printf("\n%lu\n", sizeof(struct Complex_Type));

  printf(
      "\nname = %s"
      "\ntype = %d"
      "\nvalue = %d\n",
      ct.name, ct.type, ct.i
  );

  return 0;
}