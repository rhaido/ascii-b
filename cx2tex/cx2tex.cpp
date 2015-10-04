#include <iostream>

#include "cx2tex.h"

using namespace std;

int main (int argc, char **argv) {
  cx_board t;

  if (argv[1] != NULL)
    t.open (argv[1]);
  else
    t.open ();

  t.translate();

  return 0;
}
