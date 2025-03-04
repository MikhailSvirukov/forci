#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int length = 0;
  if (argc != 3) {
    return 2;
  }
  int i = 0;
  FILE *file = fopen(argv[1], "r");
  FILE *output = fopen(argv[2], "w");
  char *t = malloc(3);
  while (fread(t, 3, 1, file)) {
    char first = t[0] >> 2;
    char second = ((t[0] & 0x3) << 4) + (t[1] >> 4);
    char third = ((t[1] << 2) & 0x3c) + (t[2] >> 6);
    char fouth = t[2] & 0x3f;
    fprintf(output, "%c %c %c %c ", first, second, third, fouth);
    i += 4;
  }
}