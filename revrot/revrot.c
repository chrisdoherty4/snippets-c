
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <math.h>

bool reversable(char* start, int size);
void reverse(char* start, int size);
void rotate(char* start, int size);

char* revrot(char* s, int size)
{
  int len = strlen(s);

  if (size <= 0 || memcmp(s, "", len) == 0) return "";

  int chunks = len / size;
  char* buf = (char*) malloc(sizeof(char) * len + 1);
  char* front = buf;
  int i = 0;

  if (!buf) {
    fprintf(stderr, "Failed to assign memory\n");
    exit(1);
  }

  strcpy(buf, s);

  while (i < chunks) {
    if (reversable(buf, size)) {
      reverse(buf, size);
    } else {
      rotate(buf, size);
    }

    buf+= size;
    i++;
  }

  *buf = '\0';

  return front;
}

bool reversable(char* buf, int size)
{
  long sum = 0;
  long digit = 0;
  int i = 0;

  if (!buf) {
    fprintf(stderr, "buf is null\n");
    exit(1);
  }

  char num[2] = { 0, '\0' };
  while (i < size) {
    num[0] = *buf;
    digit = strtol(num, NULL, 10);

    if (errno != 0) {
      fprintf(stderr, "Failed to convert to long\n");
      exit(1);
    }

    sum += digit * digit * digit;
    ++buf;
    ++i;
  }

  return (sum % 2 == 0 ? true : false);
}

void reverse(char* buf, int size)
{
  char temp = 0;
  if (!buf) {
    fprintf(stderr, "buf argument is null\n");
    exit(1);
  }

  int i = 0;
  int j = size - 1;
  while (i < j) {
    temp = *(buf + i);
    *(buf + i) = *(buf + j);
    *(buf + j) = temp;
    i++;
    j--;
  }
}

void rotate(char* buf, int size)
{
  char temp = 0;
  int i = 0;

  if (!buf) {
    fprintf(stderr, "buf is null\n");
  }

  temp = *buf;

  for (i = 0; i < size - 1; i++) {
    *(buf + i) = *(buf + i + 1);
  }

  *(buf + (size - 1)) = temp;
}

int main(int argc, char *argv[])
{
  printf("%s\n", revrot("1122345500", 4));
}
