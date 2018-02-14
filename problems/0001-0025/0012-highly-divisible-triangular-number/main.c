#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT_NTH_TRIANGULAR_NUMBER 12500

int *GenerateEratosthenesSieveShell(int upper_bound, int *ptr_amount_primes);
int *ParseEratosthenesSieve(int *ptr_sieve, int amount_primes);
int **InitPrimeFactorisationMatrix(int *ptr_primes, int rows, int cols);
void PrimeFactoriseNumber(int number, int **ptr_factorisation_matrix, int *ptr_primes, int amount_primes);
int CalculateNthTriangularNumber(int num);
int CalculateNumberOfDivisors(int **ptr_factorisation_matrix, int amount_primes);

int main(void) {

    int *ptr_sieve = NULL,
        *ptr_primes = NULL,
        *ptr_amount_primes = NULL,
        **ptr_factorisation_triangular_number = NULL;
    int nth_triangular_num = LIMIT_NTH_TRIANGULAR_NUMBER,
        sieve_upper_bound = CalculateNthTriangularNumber(nth_triangular_num),
        amount_primes = (sieve_upper_bound - 2),
        triangular_number = 0,
        number_of_divisors = 1;

    ptr_amount_primes = &amount_primes;

    ptr_sieve = GenerateEratosthenesSieveShell(sieve_upper_bound, ptr_amount_primes);

    ptr_primes = ParseEratosthenesSieve(ptr_sieve, amount_primes);

    while ( number_of_divisors < 500 ) {
        triangular_number = CalculateNthTriangularNumber(nth_triangular_num);

        ptr_factorisation_triangular_number = InitPrimeFactorisationMatrix(ptr_primes, 2 , amount_primes);
        PrimeFactoriseNumber(triangular_number, ptr_factorisation_triangular_number, ptr_primes, amount_primes);

        number_of_divisors = CalculateNumberOfDivisors(ptr_factorisation_triangular_number, amount_primes);

        free(ptr_factorisation_triangular_number);
        ptr_factorisation_triangular_number = NULL;

        nth_triangular_num--;
    }

    printf("%d\n", triangular_number);

    free(ptr_primes);
    ptr_primes = NULL;

    return 0;
}

int *GenerateEratosthenesSieveShell(int upper_bound, int *ptr_amount_primes) {

    int i = 0, j = 0, k = 0;
    int *ptr_sieve = malloc((upper_bound - 2) * sizeof *ptr_sieve);

    for ( ; i <= upper_bound - 2 ; i++ ) {
        ptr_sieve[i] = 1;
    }

    for ( i = 2 ; i < sqrt(upper_bound) ; i++ ) {
        if ( ptr_sieve[i-2] == 1) {
            k = 0;
            j = ( pow(i, 2) + k * i );
            while ( j <= upper_bound ) {
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

int CalculateNthTriangularNumber(int num) {

    int triangular_number = 0;

    triangular_number = 0.5 * num * (num + 1);

    return triangular_number;
}

int CalculateNumberOfDivisors(int **ptr_factorisation_matrix, int amount_primes) {

    int divisors = 1,
        i = 0;

    for ( ; i < amount_primes ; i++ ) {
        if ( ptr_factorisation_matrix[1][i] > 0 ) {
            divisors *= (ptr_factorisation_matrix[1][i] + 1);
        }
    }

    return divisors;
}
