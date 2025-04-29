#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PURPLE "\033[0;35m"

// https://stackoverflow.com/questions/5141960/get-the-current-time-in-c

int main() {
  time_t raw_time;
  struct tm* time_info;
  while (1) {
    sleep(1);
    system("clear");                  // clear terminal
    time(&raw_time);                  // update time
    time_info = localtime(&raw_time); // update time info
    printf("%sCurrent local time and date: %s", PURPLE,  asctime(time_info)); // display the time
  }
  return 0;
}
