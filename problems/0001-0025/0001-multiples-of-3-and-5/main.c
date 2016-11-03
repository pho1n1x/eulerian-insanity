#include <stdio.h>

#define RANGE 1000

unsigned int count_divisibility(unsigned int divisor) {
    int count = 0;

    for ( int i = 1 ; i < RANGE ; i++ ) {
        if ( i % divisor == 0 ) {
            count++;
        }
    }

    return count;
}

// Use the identity n(n+1)/2 to calculate the sum
unsigned int calculate_divisibility_sum(unsigned int number, unsigned int count) {
    unsigned int divisibility_sum = 0;

    divisibility_sum = number * (count * (count + 1)) / 2;

    return divisibility_sum;
}

int main() {
    unsigned short div_three_count = 0,
                   div_five_count = 0,
                   div_fifteen_count = 0;

    unsigned int div_three_sum,
                 div_five_sum,
                 div_fifteen_sum,
                 total_sum;

    div_three_count = count_divisibility(3);
    div_five_count = count_divisibility(5);
    div_fifteen_count = count_divisibility(15);

    div_three_sum = calculate_divisibility_sum(3, div_three_count);
    div_five_sum = calculate_divisibility_sum(5, div_five_count);
    div_fifteen_sum = calculate_divisibility_sum(15, div_fifteen_count);

    total_sum = div_three_sum + div_five_sum - div_fifteen_sum;

    printf("%d", total_sum);
    return 0;
}
