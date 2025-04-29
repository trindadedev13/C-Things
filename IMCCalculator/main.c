#include <stdio.h>

struct user {
  float weight;
  float height;
};

int main() {
  struct user usr;

  // asks weight to user
  printf("Type your weight:");
  scanf("%f", &usr.weight);

  // asks height to user
  printf("Type your height(cm):");
  scanf("%f", &usr.height);

  printf("\n");

  // calc
  usr.height = usr.height / 100.0;
  float imc = (float) (usr.weight / (usr.height * usr.height));

  // result
  printf("Your IMC: %f\n", imc);

  if (imc < 18.5f) {
    printf("You are underweight.\n");
  } else if (imc >= 18.5f && imc <= 24.9f) {
    printf("Normal weight\n");
  } else if (imc >= 25.0f && imc <= 29.9f) {
    printf("You are overweight.\n");
  } else if (imc >= 30.0f) {
    printf("You are obese!!!\n");
  }

  return 0;
}
