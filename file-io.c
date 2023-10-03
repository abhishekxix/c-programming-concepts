#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /**
   * File I/O refers to storage/retrieval of data to/from files. A file, or more
   * generically, a stream is either a data source or target.
   *
   * C works with streams using FILE pointers. FILE is a struct defined in the
   * stdio.h header file that can be used to read/write from/to streams.
   *
   * There are three streams that are available by default:
   *  - stdin  -> Standard input stream(usually the keyboard).
   *  - stdout -> Standard output stream(usually the terminal).
   *  - stderr -> Standard error stream (needs to be redirected to an output
   *    stream.)
   *
   * FOPEN_MAX determines the maximum number of streams that can be used at once
   * in a program.
   *
   * The process of using a stream is the following three steps:
   *  1. Open a stream
   *  2. Use the stream
   *  3. Close the stream
   *
   */

  /**
   * The fopen function is used to open a stream as follows.
   * The first argument is the path to the file, the second is the mode.
   */
  FILE* fptr = fopen("./testfile", "w");

  // this is essentially the same as fptr != NULL
  // Because NULL is 0 valued void pointer, and 0 is false.
  if (fptr) {
    char message[] = "hello this is a file output thing";
    char* word = strtok(message, " ");

    while (word) {
      /**
       * Writes a string to a output stream.
       *
       * Does not write the \0 to the file. So, we need to either write that
       * manually or just put a \n instead.
       */
      fputs(word, fptr);
      /**
       * Writes a character to the output stream.
       */
      fputc('\n', fptr);

      word = strtok(NULL, " ");

      /**
       * We can use fprintf() to write formatted output, just like printf().
       * The difference being that we need to pass the file pointer as the first
       * argument.
       *
       * fprintf(fptr, "%s", some_string);
       * fprintf(fptr, "%d %s", some_integer, some_string);
       */
    }

    fclose(fptr);
  }

  /**
   * We can rename a file using the rename() function.
   * We must make sure that the file is not open when we are trying to rename
   * it else it might fail.
   *
   * rename_status = 0 if rename was successful, nonzero otherwise.
   */
  /*   int rename_status = rename("./testfile", "./mytestfile");

    if (rename_status) {
      printf("\nRename unsuccessful.\n");
    } else {
      printf("\nRename successful.\n");
    } */

  /**
   * We can remove a file using the remove() function.
   * We must make sure that the file is not open when we are trying to remove
   * it else it might fail.
   *
   * remove_status = 0 if removal was successful, nonzero otherwise.
   */
  /*   int remove_status = remove("./mytestfile");

    if (remove_status) {
      printf("\nRemoval unsuccessful.\n");
    } else {
      printf("\nRemoval successful.\n");
    } */

  /**
   * Reading from a file.
   */
  fptr = fopen("./testfile", "r");

  if (fptr) {
    /**
     * fgetc reads one character at a time. Returns EOF to denote that end of
     file has been reached.
     */
    int current_character = fgetc(fptr);

    printf("\n===================FGETC===================\n");
    while (current_character != EOF) {
      printf("%c", current_character);
      current_character = fgetc(fptr);
    }
    printf("\n===================/FGETC===================\n");

    /**
     * Sets the file pointer to point to the beginning of the file.
     */
    rewind(fptr);

    char* buffer = (char*)calloc(1024, sizeof(char));
    const int CUSTOM_BUFFER_SIZE = 1023;

    if (buffer) {
      printf("\n===================FGETS===================\n");

      /**
       * Reads the contents of a stream as string.
       *
       * The string is read into the character buffer passed to the function.
       * The number of characters read into the buffer is determined by the
       * second argument to the function call or until \n is encountered,
       * whichever comes first.
       *
       * When \n is encountered, it is put into the buffer and \0 is added.
       *
       * NULL is returned when EOF is read.
       *
       */
      while (fgets(buffer, CUSTOM_BUFFER_SIZE, fptr)) {
        printf("%s", buffer);
      }
      free(buffer);
      printf("\n===================/FGETS===================\n");
    }

    fclose(fptr);
  }

  /**
   * There is also a function to read formatted text from the stream.
   *
   * The function is fscanf(), This works similar to scanf with the exception
   * that it takes in a file pointer too.
   *
   * fscanf(fptr, "%s", some_string);
   * fscanf(fptr, "%d %s", some_integer_address, some_string);
   */

  fptr = fopen("./random-access.txt", "r+");

  if (fptr) {
    /**
     * Random access in a stream.
     *
     * To achieve random access in a file, there are two functions that are
     * provided by C.
     *
     * Get current position
     *  - ftell(file_pointer)
     *    - Returns a long integer that represents the offset from the beginning
     *      of the file.
     *    - Returns -1L in case of an error.
     *    - cannot read large files in case of a 32 bit long. (Generally
     *      most systems are 64 bit nowadays, so this is not a problem.)
     *  - fgetpos() // can read large files.
     *
     * Go to a given position
     *  - fseek(FILE* file_pointer, long int offset, int position)
     *    - Returns 0 if successful, non-zero value otherwise.
     *    - The position takes one of the following values:
     *      - SEEK_SET
     *      - SEEK_CUR
     *      - SEEK_END
     *    - cannot be used on large files in case of a 32 bit long. (Generally
     *      most systems are 64 bit nowadays, so this is not a problem.)
     *  - fsetpos() // can read large files but random access not provided.
     *
     * Putting and/or reading from the file will advance the file pointer by the
     * number of characters read/written
     */

    int seek_status = fseek(fptr, 0L, SEEK_END);
    long file_size = 0;

    if (seek_status == 0) {
      file_size = ftell(fptr);
    }

    if (file_size) {
      long center_of_file = file_size / 2L;

      fseek(fptr, center_of_file, SEEK_SET);

      int curr_char = fgetc(fptr);
      fseek(fptr, -1L, SEEK_CUR);
      fputc(curr_char == '0' ? '1' : '0', fptr);
    }

    fclose(fptr);
  }
}