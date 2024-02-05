#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0x4c4c4114

struct dbheader_t {
  unsigned int magic;
  unsigned short version;
  unsigned short count;
  unsigned int filesize;
};

struct employee_t {
  char name[256];
  char address[256];
  unsigned int hours;
};

int create_db_header(int fd, struct dbheader_t **header_out);
int validate_db_header(int fd, struct dbheader_t **header_out);
int read_employees(int fd, struct dbheader_t *,
                   struct employee_t **employees_out);

#endif // !PARSE_H