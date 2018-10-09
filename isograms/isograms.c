#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>

bool IsIsogram(const char *str)
{
  int counts[26] = { 0 };

  for (; *str != '\0'; str++) {
    if (counts[((char) tolower(*str)) - 'a']++) {
      return false;
    }
  }

  return true;
}

int main()
{
  const char *w1 = "HelloWorld";
  assert(!IsIsogram(w1));
  assert(IsIsogram("abCdeFghijl"));
  assert(!IsIsogram("apsAwje"));
  assert(!IsIsogram("aABb"));

  printf("All tests passed\n");

  return 0;
}
