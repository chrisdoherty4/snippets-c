#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool isPrime(long long n);
long long floorSqrt(long long x);

long long* gap(int g, long long m, long long n)
{
  long long max, temp;
  bool currentIsPrime = false;
  long long* primes = (long long*) calloc(2, sizeof(long long));

  // We can't find a pair g apart if m and n are equal.
  // We can't find a pair g apart if m + g is greater than n.
  if (m == n || m + g > n)
    return primes;

  // Find a pair and check each value between the pair to ensure they aren't
  // prime.
  for (; m <= n; m++) {

    // If we have a prime pair and are still iterating between them, check if
    // the current m is prime.
    if (primes[0]) {
      if (m >= primes[1]) {
        break;
      } else if (isPrime(m)) {
        currentIsPrime = true;
        primes[0] = primes[1] = 0;
      }
    }

    // Check for a prime pair if we don't already have a prime pair.
    if (!primes[0] && (temp =  m + g) < n && (currentIsPrime || isPrime(m)) && isPrime(temp)) {
      primes[0] = m;
      primes[1] = temp;
    }

    currentIsPrime = false;
  }

  return primes;
}

bool isPrime(long long n)
{
  long i;

  if (n % 2 == 0)
    return false;

  for(i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

int main()
{
  long long* res;

  res = gap(2, 100, 110);
  assert(*res == 101 && *(res + 1) == 103);

  res = gap(6, 100, 110);
  assert(*res == 0 && *(res + 1) == 0);

  return 0;
}
