#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_LIMIT  50
#define NUMBER_LIMIT 100

int *DynamicArrayAppend (int *ary, int size);

int main(void) {

  FILE *fp_aux = NULL;
  int *ptr_sum = NULL;
  int input_ary[NUMBER_LIMIT][DIGIT_LIMIT],
      digit = 0, num = 0, val = 0,
      i = 0, j = 0, size = 0, remainder = 0;
  unsigned int col_sum = 0;
  char buffer[DIGIT_LIMIT+1];

  fp_aux = fopen("../../../addendum/0013.txt", "r");

  if (fp_aux == NULL) {
    printf("Nay!\n");
    return 1;
  } else {
    while ( fgets(buffer, DIGIT_LIMIT+2, fp_aux) != NULL && strlen(buffer) > 1) {
      buffer[50] = '\0';
      for ( digit = 0 ; digit < DIGIT_LIMIT ; digit++ ) {
        input_ary[num][digit] = buffer[digit] - '0';
      }
      num++;
    }
  }

  for ( i = DIGIT_LIMIT ; i > 0 ; i-- ) {
    for ( j = 0 ; j < NUMBER_LIMIT ; j++ ) {
      col_sum += input_ary[j][i-1];
    }
    size++;
    ptr_sum = DynamicArrayAppend(ptr_sum, size);
    ptr_sum[size-1] = col_sum % 10;
    col_sum /= 10;
  }

  remainder = col_sum;

  while ( remainder != 0 ) {
    size++;
    ptr_sum = DynamicArrayAppend(ptr_sum, size);
    ptr_sum[size-1] = remainder % 10;
    remainder /= 10;
  }

  for ( i = size ; i > 0 ; i-- ) {
    printf("%d", ptr_sum[i-1]);
  }

  fclose(fp_aux);
  free(ptr_sum);
  ptr_sum = NULL;
  return 0;
}

int *DynamicArrayAppend (int *ary, int size) {
  int *ptr_ary = realloc(ary, size * sizeof *ptr_ary);

  return ptr_ary;
}
