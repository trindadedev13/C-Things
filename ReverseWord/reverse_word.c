#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define CYAN "\033[0;36m"

struct app_state {
  char* word;                      // the normal word
  char* reversed_word;             // the reversed word
  char reversed_word_buffer[1024]; // the buffer used to create reversed word
};

int main() {
  struct app_state state;
  state.word = malloc(1024);
  state.reversed_word = malloc(1024);

  printf("Type an word to be reversed: ");
  scanf("%1023s", state.word);

  // reverse word
  int word_len = strlen(state.word);
  int j = 0;
  for (int i = word_len - 1; i >= 0; i--) {
    state.reversed_word_buffer[j] = state.word[i];
    j++;
  }
  state.reversed_word_buffer[j] = '\0';

  strcpy(state.reversed_word, state.reversed_word_buffer);

  // prints the reversed word in cyan
  printf("%s%s%s\n", CYAN, state.reversed_word, RESET);

  // desalocate memory
  free(state.word);
  free(state.reversed_word);

  return 0;
}
