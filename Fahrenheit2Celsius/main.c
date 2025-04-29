#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char* STR_PROGRAM_NAME = "Fahrenheit2Celsius";
const char* STR_PLEASE_TYPE_AN_VALUE = "Please type an value";
const char* STR_FAHRENHEIT = "Fahrenheit";
const char* STR_CELSIUS = "Celsius";
const char* STR_INSTRUCTIONS = "Use *value*f to fahrenheit\nUse *value*c to celsius";
const char* SYMBOL_F = "F";
const char* SYMBOL_C = "C";
const int TYPE_FAHRENHEIT = 0;
const int TYPE_CELSIUS = 1;

float to_celsius(float fahrenheit) {
  return (fahrenheit - 32) / 1.8;
}

float to_fahrenheit(float celsius) {
  return (celsius * 1.8) + 32;
}

int handle_type(char type[20]) {
  for (int i = 0; i < strlen(type); i++) {
    type[i] = toupper(type[i]);
  }
  if (strstr(type, SYMBOL_F) != NULL) {
    return TYPE_FAHRENHEIT;
  } else {
    return TYPE_CELSIUS;
  }
}

int main() {
  printf("%s\n", STR_PROGRAM_NAME);

  // ask to user an value
  char input[20];
  printf("%s\n\n%s\n", STR_PLEASE_TYPE_AN_VALUE, STR_INSTRUCTIONS);
  scanf("%s", input);
  
  char* ptr;
  float input_as_float = strtof(input, &ptr);
  int type = handle_type(ptr);

  if (type == TYPE_FAHRENHEIT) {
    // fahrenheit to celsius
    printf("%s: %.2f\n", STR_CELSIUS,  to_celsius(input_as_float));
  } else {
    // celsius to fahrenheit
    printf("%s: %.2f\n", STR_FAHRENHEIT, to_fahrenheit(input_as_float));
  }
  return 0; // finish program
}