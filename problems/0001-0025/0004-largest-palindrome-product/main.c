#include <stdio.h>

#define LOWER_BOUND   100
#define UPPER_BOUND   999

unsigned int reverse_number(unsigned int num);

int main() {
  unsigned short i = 0, j = 0;
  char found = 0;
  unsigned int num = 0, rev_num = 0;
  unsigned int max_palindrome = 0;

  for ( i = UPPER_BOUND ; i >= LOWER_BOUND && i <= UPPER_BOUND ; i-- ) {
    for ( j = UPPER_BOUND ; j >= LOWER_BOUND && j <= UPPER_BOUND ; j-- ) {
      num = i * j;
      rev_num = reverse_number(num);
      if ( num == rev_num && num > max_palindrome ) {
        max_palindrome = num;
      }
    }
  }

  printf("%d", max_palindrome);

  return 0;
}

unsigned int reverse_number(unsigned int num) {
  unsigned int rev_num = 0;

  while ( num != 0 ) {
    rev_num = rev_num * 10 + num % 10;
    num /= 10;
  }

  return rev_num;
}
