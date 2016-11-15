#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *EratosthenesSieve(unsigned int num);

int main(void) {
  int *sieve;
  const unsigned int LIMIT = 2000000;
  unsigned long long prime_sum = 0;

  sieve = EratosthenesSieve(LIMIT);
  for ( int i = 0 ; i < (LIMIT - 2) ; i++) {
    if ( sieve[i] == 1 ) {
      prime_sum += i + 2;
    }
  }

  printf("%llu", prime_sum);

  free(sieve);
  sieve = NULL;

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
