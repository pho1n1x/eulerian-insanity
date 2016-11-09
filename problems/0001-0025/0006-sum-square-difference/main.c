#include <stdio.h>

unsigned int SumOfSquares(unsigned int num);
unsigned int SquareOfSums(unsigned int num);

int main() {
  const unsigned int RANGE = 100;
  unsigned int difference = 0;

  difference = SquareOfSums(RANGE) - SumOfSquares(RANGE);

  printf("%d", difference);

  return 0;
}

/* Use Faulhaber's Formula special case to
 * calculate the nth Square pyramidal number
 * which is the sum of the squares from 1 to num */
unsigned int SumOfSquares(unsigned int num) {
  unsigned int sum = 0;

  sum = ( num * (num + 1) * (2*num + 1) ) / 6;

  return sum;
}

/* Calculate the nth Triangular number */
unsigned int SquareOfSums(unsigned int num) {
  unsigned int sum = 0;

  sum = ( num * ( num + 1) ) / 2;
  sum *= sum;

  return sum;
}
