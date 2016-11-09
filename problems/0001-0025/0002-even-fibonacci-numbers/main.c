#include <stdio.h>
#include <math.h>

#define LIMIT 4000000

unsigned int BinetsFormula(unsigned int num);

int main(void) {

  unsigned int i = 2,
               nth_fib_element = 0,
               even_fib_sum = 0;

  while ( nth_fib_element < LIMIT ) {
    nth_fib_element = BinetsFormula(i);
    if ( nth_fib_element % 2 == 0 && nth_fib_element < LIMIT ) {
      even_fib_sum += nth_fib_element;
    }
    i++;
  }

  printf("%d", even_fib_sum);

  return 0;
}

/* Use Binet's Formula as a closed-form solution
 * to calculate the n-th element of the Fibinacci sequence */
unsigned int BinetsFormula(unsigned int num) {
  double PHI = (1.0 + sqrt(5)) / 2.0;
  unsigned int fibonacci_number = 0;

  fibonacci_number = (pow(PHI, num) - pow(1 - PHI, num)) / sqrt(5);

  return fibonacci_number;
}
