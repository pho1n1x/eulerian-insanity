#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *EratosthenesSieve(unsigned int num);

int main() {
  const unsigned int LIMIT = 125000;
  int count = 0;
  char *sieve = NULL;

  sieve = EratosthenesSieve(LIMIT);

  for ( int i = 0 ; i < (LIMIT - 2) ; i++ ) {
    if ( sieve[i] == 1) {
      count++;
      if ( count == 10001 ) {
        printf("%d", i+2);
        free(sieve);
        sieve = NULL;
        return 0;
      }
    }
  }

  free(sieve);
  sieve = NULL;

  return 0;
}

char *EratosthenesSieve(unsigned int num) {
  int i = 0, j = 0, k = 0;
  char *sieve = malloc((num - 2) * sizeof * sieve);

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
