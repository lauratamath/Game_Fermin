#define SDL_MAIN_HANDLED
#include <print.h>
#include <string>

#include "Pong/Pong.h"

int main () {
  print("INIT");
  Pong pong = Pong("pong", 800, 600);
  print("MAIN INSTANCE");
  pong.run();

  return 0;
}