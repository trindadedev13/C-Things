#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESET "\033[0m"
#define GREEN "\033[0;32m"

static char* generate(int len) {
  const char charset[] =
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "0123456789";
  char* password = malloc(len);
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    password[i] = charset[rand() % strlen(charset)];
  }
  return password;
}

int main() {
  int len = 1;

  printf("Type the length of password: ");
  scanf("%d", &len);

  char* pass = generate(len);
  printf("%sGenerated Password: %s\n%s", GREEN, pass, RESET);

  free(pass);

  return 0;
}
