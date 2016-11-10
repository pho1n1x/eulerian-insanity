#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *EratosthenesSieve(unsigned int num);

int main() {
  unsigned long long num = 600851475143uLL;
  unsigned int divisor_limit = 0, max_factor = 0;
  unsigned int i = 0;
  int *sieve;

  divisor_limit = floor(sqrt(num));

  /* Use the Sieve of Eratosthenes to
   * search for all the possible prime divisors */
  sieve = EratosthenesSieve(divisor_limit);

  while ( num != 1 ) {
    for ( i = 0 ; i < (divisor_limit - 2) ; i++ ) {
      if ( sieve[i] == 1 && num % (i + 2) == 0 ) {
        if ( max_factor <= i+2 ) {
          max_factor = i + 2;
        }
        num /= i+2;
        break;
      }
    }
  }

  free(sieve);
  sieve = NULL;

  printf("%d", max_factor);

  return 0;
}

int *EratosthenesSieve(unsigned int num) {
  int i = 0, j = 0, k = 0;
  int *sieve = malloc(sizeof(int)*(num - 2));

  /* Seed the array with 1s as the
   * first step of the sieve algorithm */
  for ( i = 0 ; i < (num - 2) ; i++ ) {
    sieve[i] = 1;
  }

  for ( i = 2 ; i < sqrt(num) ; i++ ) {
    if ( sieve[i-2] == 1) {
      k = 0;
      j = ( pow(i, 2) + k * i );
      while ( j < num ) {
        sieve[j-2] = 0;
        k++;
        j = ( pow(i, 2) + k * i );
      }
    }
  }

  return sieve;
}
