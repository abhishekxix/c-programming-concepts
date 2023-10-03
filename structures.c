#include <stdio.h>
#include <stdlib.h>

/**
 * Correct way - using a structure to define a date type.
 *
 * This makes sure that each date contains all the information about itself.
 * Even if we want to change the definition of what a date is, we just need to
 * do it at one place.
 */
struct Date {
  int day;
  int month;
  int year;
};

void print_the_date(struct Date date) {
  printf(
      "\n{day = %d, month = %d, year = %d}\n", date.day, date.month, date.year
  );
}

int main() {
  /**
   * Let's assume that we want to create a program that deals with dates. One
   * way to store the day, month, and year for the date could be by using three
   * different variables for a single date.
   *
   * However, we can see how this could quickly turn into a problem if we want
   * to have more than one dates that we want to store in the program. What if
   * we want to store 100 dates for instance?
   *
   * There are two possible ways to deal with that problem:
   *    1. Declare 300 variables, 3 for each date.
   *      - This is not sustainable if we want to create anything that is
   *        dynamic in nature.
   *    2. Declare 3 arrays, one for date, one for month, one for year to store
   *       multiple dates. This approach has the following major flaws:
   *       - What if we want to be able to store the time along with the date?
   *          This would lead to definition of three more arrays for hour,
   *          minute, second, and so on for any each increasing attribute that
   *          needs to be supported by our program.
   *       - Notice how the data of a single date is split into multiple arrays,
   *         More number of arguments to pass to a function if we want to
   *         operate on a date. More number of arrays that we need to worry
   *         about. We have to update several different arrays to add, edit, or
   *         remove a date.
   *       - Deletion from random positions in an array can be an expensive
   *         operation.
   *       - Addition of a date could potentially require the array to be
   *         allocated again, along with being copied to the new memory, causing
   *         performance issues, considering that we need to perform these
   *         operations on multiple arrays to deal with a single date.
   *
   * There must be a better way to deal with this, right?
   * Yes, there is a way to deal with all these problems. The answer is a
   * structure. Structures are user defined data types that may contain
   * heterogenous member elements.
   *
   */

  // Problematic ways of dealing with complex entities like dates.
  // Using separate variables.
  int day = 3;
  int month = 10;
  int year = 2001;

  // Using arrays.
  int days[1000] = {0};
  int months[1000] = {0};
  int years[1000] = {0};

  // Check line 10 to see how a structure type is defined.
  struct Date today;

  // To initialize the values of a struct type variable, we can do a few things.
  /**
   *  First approach -
   *  day will become 4, month will become 10, year will become 2023
   */
  struct Date tomorrow = {4, 10, 2023};

  /**
   *  Second approach -
   *  day will become 4, month will become 10, year will become 2023
   *
   * This one is more readable
   */
  struct Date yesterday = {.day = 4, .month = 10, .year = 2023};

  /**
   * To access the members of a struct type.
   */
  printf(
      "Yesterday was %d/%d/%d\n", yesterday.day, yesterday.month, yesterday.year
  );

  /**
   * To change the values of a struct variable.
   */
  today.day = 3;
  today.month = 10;
  today.year = 2023;

  print_the_date(today);

  // Array of a structure type
  struct Date dates[3] = {
      {.day = 1, .month = 12, .year = 2023},
      {.day = 2, .month = 11, .year = 2022},
      {.day = 3, .month = 10, .year = 2021}
  };

  for (int i = 0; i < 3; i++) {
    print_the_date(dates[i]);
  }

  // pointer to a structure type
  struct Date* date_ptr = &today;

  // To access the members of a struct type pointer, we have two ways.
  // First way.
  printf("\nToday date: %d\n", (*date_ptr).day);

  // Second way, a nicer syntax to do the same thing.
  printf("\nToday month: %d\n", date_ptr->month);

  // Allocating a structure type dynamically
  date_ptr = (struct Date*)malloc(sizeof(struct Date));

  date_ptr->day = tomorrow.day;
  date_ptr->month = tomorrow.month;
  date_ptr->year = tomorrow.year;
  print_the_date(*date_ptr);

  free(date_ptr);
  return 0;
}