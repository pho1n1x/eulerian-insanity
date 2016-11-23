#include <stdio.h>

unsigned int CollatzSequenceCount(unsigned int num);

int main() {
  unsigned int longest_sequence = 0,
               tmp_sequence = 0,
               num = 0,
               i = 0;
  const unsigned int LIMIT = 1000000;

  for ( i = 1 ; i < LIMIT ; i++ ) {
    tmp_sequence = CollatzSequenceCount(i);
    if ( tmp_sequence > longest_sequence ) {
      longest_sequence = tmp_sequence;
      num = i;
    }
  }

  printf("%d", num);

  return 0;
}

/* Use the Collatz Sequence to return the count of
 * terms the passed in number */
unsigned int CollatzSequenceCount(unsigned int num) {
  unsigned int count = 1;

  while ( num != 1) {
    if ( num % 2 == 0 ) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    count++;
  }

  return count;
}
