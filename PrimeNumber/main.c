#include <stdio.h>

const char* STR_PROGRAM_NAME = "PrimeNumber";
const char* STR_TYPE_AN_NUMBER = "Type an Number";
const char* STR_PRIME_NUMBER = "Its a Prime Number";
const char* STR_NOT_PRIME_NUMBER = "Its not a Prime Number";

int main() {
  printf("%s\n", STR_PROGRAM_NAME);
  printf("%s\n", STR_TYPE_AN_NUMBER);
  int i, input;
  do {
    scanf("%d", &input);
  } while (input <= 1);
  for (i = 2; i < input; i++) {
    if (input % i == 0) {
      break;
    }
  }
  if (input == i) {
    printf("%s\n", STR_PRIME_NUMBER);
  } else {
    printf("%s\n", STR_NOT_PRIME_NUMBER);
  }
  return 0;
}
