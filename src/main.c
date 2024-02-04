#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

void print_usage() { printf("Usage:"); }

int main(int argc, char *argv[]) {
  char *file_path = NULL;
  bool new_file = false;
  int c;

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
    print_usage();

    return 0;
  }

  printf("New file: %d\n", new_file);
  printf("File path: %s\n", file_path);

  return 0;
}
