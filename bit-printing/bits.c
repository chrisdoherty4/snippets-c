#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

const char* bits(const unsigned char val)
{
  int i, j, size;
  char* store;

  size = CHAR_BIT * sizeof(val);
  store = calloc(size + 1, sizeof(char));

  for (i = 0, j = size - 1; i < size; i++, j--) {
    store[j] = (val >> i) & 0x01 ? '1' : '0';
  }

  store[size] = '\0';

  return store;
}

int main()
{
  printf("%-4s = %s\n", "1", bits(1));
  printf("%-4s = %s\n", "2", bits(2));
  printf("%-4s = %s\n", "3", bits(3));
  printf("%-4s = %s\n", "4", bits(4));
  printf("%-4s = %s\n", "5", bits(5));
  printf("%-4s = %s\n", "6", bits(6));
  printf("%-4s = %s\n", "7", bits(7));
  printf("%-4s = %s\n", "8", bits(8));
  printf("%-4s = %s\n", "16", bits(16));
  printf("%-4s = %s\n", "32", bits(32));
  printf("%-4s = %s\n", "64", bits(64));
  printf("%-4s = %s\n", "128", bits(128));
  printf("%-4s = %s\n", "255", bits(255));

  return 0;
}
