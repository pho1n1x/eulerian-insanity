#include <stdio.h>

int main(void) {

    int m = 2,
        n = 1,
        first_leg = 0,
        second_leg = 0,
        hypotenuse = 0,
        sum_of_pythagorean_triple = 0,
        product_of_pythagorean_triple = 0;

    for ( ; m <= 20 ; m++ ) {
        n = 1;
        for ( ; n < m ; n++ ) {
            first_leg = (m * m) - (n * n);
            second_leg = 2 * m * n;
            hypotenuse = (m * m) + (n * n);
            sum_of_pythagorean_triple = first_leg + second_leg + hypotenuse;

            if ( sum_of_pythagorean_triple == 1000 ) {
                product_of_pythagorean_triple = first_leg * second_leg * hypotenuse;
                printf("%d\n", product_of_pythagorean_triple);
            }
        }
    }

    return 0;
}
