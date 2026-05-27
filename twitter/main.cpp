#include <stdio.h>
#include <stdlib.h>

static int (*func)();

static int evil() {
  printf("Hello world!");
  return 0;
}

void dummy() { func = evil; }

int main() { return func(); }
