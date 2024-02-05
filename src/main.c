#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

#include "common.h"
#include "file.h"

void print_usage(char *argv[]) {
  printf("Usage: %s -n -f <database file>\n", argv[0]);
  printf("\t -n: Create a new database file\n");
  printf("\t -f: (required) Path to the database file\n");

  return;
}

int main(int argc, char *argv[]) {
  char *file_path = NULL;
  bool new_file = false;
  int c;
  int dbfd = -1;

  while ((c = getopt(argc, argv, "nf:")) != -1) {
    switch (c) {
    case 'n':
      new_file = true;
      break;
    case 'f':
      file_path = optarg;
      break;
    case '?':
      printf("Unknown option -%c\n", c);
      break;
    default:
      return -1;
    }
  }

  if (file_path == NULL) {
    printf("File path is a required argument\n");
    print_usage(argv);

    return 0;
  }

  if (new_file) {
    dbfd = create_db_file(file_path);
    if (dbfd == STATUS_ERROR) {
      printf("Failed to create new file\n");
      return -1;
    }
  } else {
    dbfd = open_db_file(file_path);
    if (dbfd == STATUS_ERROR) {
      printf("Failed to open file\n");
      return -1;
    }
  }

  printf("New file: %d\n", new_file);
  printf("File path: %s\n", file_path);

  return 0;
}
