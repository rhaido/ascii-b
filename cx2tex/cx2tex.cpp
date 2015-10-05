#include <iostream>

#include "cx2tex.h"

using namespace std;

int main (int argc, char **argv) {
  cx_board t;
  int res = 0;

  if (argv[1] != NULL) {
    res = t.open (argv[1]);

    if (res != 0)
      return res;
  }
  else
    t.open ();

  t.translate();

  return 0;
}
