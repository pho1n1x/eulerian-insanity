#include <stdio.h>

#define RANGE 1000

unsigned short CountDivisibility(unsigned short divisor);
unsigned int CalculateDivisibilitySum(unsigned short num, unsigned short cnt);

int main() {
  unsigned short div_three_count = 0,
                 div_five_count = 0,
                 div_fifteen_count = 0;

  unsigned int div_three_sum,
               div_five_sum,
               div_fifteen_sum,
               total_sum;

  div_three_count = CountDivisibility(3);
  div_five_count = CountDivisibility(5);
  div_fifteen_count = CountDivisibility(15);

  div_three_sum = CalculateDivisibilitySum(3, div_three_count);
  div_five_sum = CalculateDivisibilitySum(5, div_five_count);
  div_fifteen_sum = CalculateDivisibilitySum(15, div_fifteen_count);

  total_sum = div_three_sum + div_five_sum - div_fifteen_sum;

  printf("%d", total_sum);

  return 0;
}

unsigned short CountDivisibility(unsigned short divisor) {
  unsigned short cnt = 0;

  cnt = (RANGE - 1) / divisor;

  return cnt;
}

/* Use the identity n(n+1)/2 to calculate the sum */
unsigned int CalculateDivisibilitySum(unsigned short num, unsigned short cnt) {
  unsigned int divisibility_sum = 0;

  divisibility_sum = num * (cnt * (cnt + 1)) / 2;

  return divisibility_sum;
}
