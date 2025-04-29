#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI Colors
#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define YELLOW "\033[0;33m"

// The state
struct game_state {
  int number;   // the number
  int attemp;   // last attemp
  int attemps;  // number of attempts 
};

int main() {
  struct game_state state;

  srand(time(NULL));
  state.number = rand() % 100;

  do {
    printf("%sGuess the number: ", YELLOW);
    scanf("%d", &state.attemp);
    state.attemps++;
    if (state.attemps >= 1 && state.attemp != state.number) {
      printf("%sWrong!%s\n", RED, RESET);
    }
  } while (state.attemp != state.number);

  printf("%sCongrats the number is: %d%s\n", GREEN, state.number, RESET);
  printf("%sTotal attemps: %d%s\n", CYAN, state.attemps, RESET);
  return 0;
}
