#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 20

int *GenerateEratosthenesSieve(int *ptr_amount_primes);
int *ParseEratosthenesSieve(int *ptr_sieve, int amount_primes);
int **InitPrimeFactorisationMatrix(int *ptr_primes, int rows, int cols);
void PrimeFactoriseNumber(int number, int **ptr_factorisation_matrix, int *ptr_primes, int amount_primes);
void ComparePrimeFactorisation(int **ptr_factorisation_source, int **ptr_factorisation_destination, int cols);
long CalculateLeastCommonMultiple(int **ptr_factorisation_matrix, int cols);

int main(void) {

    int *ptr_sieve = NULL,
        *ptr_primes = NULL,
        *ptr_amount_primes = NULL,
        **ptr_factorisation_total = NULL,
        **ptr_factorisation_single = NULL;
    int i = 0,
        amount_primes = (LIMIT - 2);
    long lcm = 0;

    ptr_amount_primes = &amount_primes;

    ptr_sieve = GenerateEratosthenesSieve(ptr_amount_primes);
    ptr_primes = ParseEratosthenesSieve(ptr_sieve, amount_primes);

    ptr_factorisation_total = InitPrimeFactorisationMatrix(ptr_primes, 2, amount_primes);

    for ( i = 2 ; i <= LIMIT ; i++ ) {
        ptr_factorisation_single = InitPrimeFactorisationMatrix(ptr_primes, 2 , amount_primes);
        PrimeFactoriseNumber(i, ptr_factorisation_single, ptr_primes, amount_primes);
        ComparePrimeFactorisation(ptr_factorisation_single, ptr_factorisation_total, amount_primes);
        free(ptr_factorisation_single);
        ptr_factorisation_single = NULL;
    }

    free(ptr_primes);
    ptr_primes = NULL;

    lcm = CalculateLeastCommonMultiple(ptr_factorisation_total, amount_primes);
    free(ptr_factorisation_total);
    ptr_factorisation_total = NULL;

    printf("%ld\n", lcm);

    return 0;
}

int *GenerateEratosthenesSieve(int *ptr_amount_primes) {

    int i = 0, j = 0, k = 0;
    int *ptr_sieve = malloc((LIMIT - 2) * sizeof *ptr_sieve);

    for ( i = 0 ; i < (LIMIT - 2) ; i++ ) {
        ptr_sieve[i] = 1;
    }

    for ( i = 2 ; i < sqrt(LIMIT) ; i++ ) {
        if ( ptr_sieve[i-2] == 1) {
            k = 0;
            j = ( pow(i, 2) + k * i );
            while ( j < LIMIT ) {
                if ( ptr_sieve[j-2] == 1 ) {
                    ptr_sieve[j-2] = 0;
                    *ptr_amount_primes -= 1;
                }
                j = ( pow(i, 2) + k++ * i );
            }
        }
    }

    return ptr_sieve;
}

int *ParseEratosthenesSieve(int *ptr_sieve, int amount_primes) {

    int count = 0, i = 0;
    int *ptr_primes = malloc(amount_primes * sizeof *ptr_primes);

    for ( i = 0 ; count <= amount_primes ; i++ ) {
        if ( ptr_sieve[i] == 1 ) {
            ptr_primes[count++] = i + 2;
        }
    }

    free(ptr_sieve);
    ptr_sieve = NULL;

    return ptr_primes;
}

int **InitPrimeFactorisationMatrix(int *ptr_primes, int rows, int cols) {

    int i = 0;
    int **ptr_temp = NULL,
        **ptr_factorisation_matrix = NULL;

    ptr_temp = calloc(rows, sizeof *ptr_temp);
    if ( ptr_temp != NULL ) {
        ptr_factorisation_matrix = ptr_temp;
    }

    for ( i = 0 ; i < rows ; i++ ) {
        ptr_temp[i] = calloc(cols, sizeof *ptr_temp[i]);
        if ( ptr_temp != NULL ) {
            ptr_factorisation_matrix[i] = ptr_temp[i];
        }
    }

    for ( i = 0 ; i < cols ; i++ ) {
        ptr_factorisation_matrix[0][i] = ptr_primes[i];
    }

    return ptr_factorisation_matrix;
}

void PrimeFactoriseNumber(int number, int **ptr_factorisation_matrix, int *ptr_primes, int amount_primes) {

    int i = 0;

    while ( number != 1 ) {
        for ( i = 0 ; i < amount_primes ; i++) {
            if ( number % ptr_primes[i] == 0 ) {
                ptr_factorisation_matrix[1][i] += 1;
                number /= ptr_primes[i];
            }
        }
    }

    return;
}

void ComparePrimeFactorisation(int **ptr_factorisation_source, int **ptr_factorisation_destination, int cols) {

    int i = 0;

    for ( i = 0 ; i < cols ; i++ ) {
        if ( ptr_factorisation_source[1][i] > ptr_factorisation_destination[1][i] ) {
            ptr_factorisation_destination[1][i] = ptr_factorisation_source[1][i];
        }
    }

    return;
}

long CalculateLeastCommonMultiple(int **ptr_factorisation_matrix, int cols) {

    int i = 0;
    long lcm = 1;
    double base = 0, exponent = 0;

    for ( i = 0 ; i < cols ; i++ ) {
        base = (double) ptr_factorisation_matrix[0][i];
        exponent = (double) ptr_factorisation_matrix[1][i];
        lcm *= (long) pow(base, exponent);
    }

    return lcm;
}
