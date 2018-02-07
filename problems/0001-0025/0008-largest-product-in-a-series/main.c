#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUMBER_LENGTH  1000
#define BUFFER_SIZE    50
#define SEQ_LENGTH     13

void CopySubstring(int *destination, int *source, int start, int length);
int CheckForZero(int *number_array, int length);
unsigned long int CalculateProduct(int *number_array, int length);

int main(void) {

    FILE *fp_aux = NULL;
    int *input_array = malloc(NUMBER_LENGTH * sizeof *input_array);
    int *tmp_array = malloc(SEQ_LENGTH * sizeof *tmp_array);
    char buffer[50];
    int digit = 0, curr_idx = 0, found_idx = -1, count = 0;
    unsigned long int product = 0, tmp_product = 0;

    fp_aux = fopen("../../../addendum/0008.txt", "r");
    if ( fp_aux == NULL ) {
        printf("Nay! Something went wrong! >.<");
        exit(1);
    }

    while ( fgets(buffer, BUFFER_SIZE+1, fp_aux) != NULL && strlen(buffer) > 1 ) {
        for ( digit = 0 ; digit < BUFFER_SIZE ; digit++ ) {
            input_array[curr_idx++] = buffer[digit] - '0';
        }
    }

    curr_idx = 0;

    while ( curr_idx < NUMBER_LENGTH - SEQ_LENGTH  ) {
        CopySubstring(tmp_array, input_array, curr_idx, SEQ_LENGTH);

        found_idx = CheckForZero(tmp_array, SEQ_LENGTH);

        if ( found_idx < 0 ) {
            tmp_product = CalculateProduct(tmp_array, SEQ_LENGTH);
            curr_idx++;
        } else {
            curr_idx += found_idx + 1;
        }

        if ( tmp_product > product ) {
            product = tmp_product;
        }
    }

    printf("%lu\n", product);

    fclose(fp_aux);
    free(input_array);
    input_array = NULL;
    free(tmp_array);
    tmp_array = NULL;
    return 0;
}

void CopySubstring(int *destination, int *source, int start, int length) {

    int idx = 0;

    for ( ; idx < length ; idx++ ) {
        destination[idx] = source[start+idx];
    }

    return;
}

int CheckForZero(int *number_array, int length) {

    int idx = 0, found_idx = -1;

    for ( ; idx < length ; idx++ ) {
        if ( number_array[idx] == 0 ) {
            found_idx = idx;
        }
    }

    return found_idx;
}

unsigned long int CalculateProduct(int *number_array, int length) {

    unsigned long int product = 1;
    int idx = 0;

    for ( ; idx < length ; idx++ ) {
        product *= number_array[idx];
    }

    return product;
}
