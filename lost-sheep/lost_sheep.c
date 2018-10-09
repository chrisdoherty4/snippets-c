#include <assert.h>
#include <stdio.h>

int sum(const int *arr)
{
  int sum = 0;

  for (; *arr; arr++) {
    sum += *arr;
  }

  return sum;
}

int lostSheep(const int *friday, const int *saturday, int total)
{
    return total - sum(friday) - sum(saturday);
}

int main()
{
    const int friday1[] = { 1, 2, 0 }; const int saturday1[] = { 2, 3, 0 };
    assert(5 == lostSheep(friday1, saturday1, 13));

    const int friday2[] = { 5, 5, 0 }; const int saturday2[] = { 2, 2, 0 };
    assert(2 == lostSheep(friday2, saturday2, 16));

    printf("All tests passed\n");

    return 0;
}
