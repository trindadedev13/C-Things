#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBERS_COUNT 3
#define MAX_INPUTS 1024

int do_sums(char* digits_array[], int count) {
  for (int i = 0; i < count; i++) {
    char* digits = digits_array[i];
    int digits_len = strlen(digits);
    
    printf("%s = ", digits);

    int sum = 0;

    for (int j = 0; j < digits_len; j++) {
      char ch = digits[j];
      if (!isdigit(ch)) {
        printf("\nError: '%c' is not a digit\n", ch);
        return 1;
      }
      int digit = ch - '0';
      sum += digit * digit;
      printf("%d²", digit);
      if (j < (digits_len - 1)) {
        printf(" + ");
      }
    }
    printf(" = %d\n", sum);
  }
  return 0;
}

int main() {
  char input[MAX_INPUTS];
  printf("Type numbers separated by space: ");
  fgets(input, sizeof(input), stdin);

  input[strcspn(input, "\n")] = '\0';

  char* digits_array[MAX_INPUTS];
  int digits_count;

  char* token = strtok(input, " ");

  while (token != NULL && digits_count < MAX_INPUTS) {
    digits_array[digits_count++] = token;
    token = strtok(NULL, " ");
  }

  return do_sums(digits_array, digits_count);
}
