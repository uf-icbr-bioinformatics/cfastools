#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HDR 0
#define SEQ 1

void usage(char *progname) {
  printf("Usage: %s fastafile [bases]\n\n", progname);
  printf("This program reads a file in FASTA format and writes it to\n");
  printf("standard output after replacing all occurrences of one nucleotide\n");
  printf("with a different one. By default, converts Cs to Ts. A different\n");
  printf("replacement can be specified with the second argument, indicating\n");
  printf("the two bases. For example, use GA to convert Gs to As.\n\n");
}

int main(int argc, char *argv[]) {

  char *infile;
  FILE *f;
  int base;
  int state = HDR;
  int from = 'C';
  int to = 'T';

  switch (argc) {
  case 3:
    infile = argv[1];
    from = argv[2][0];
    to = argv[2][1];
    break;

  case 2:
    if (!strcmp(argv[1], "-h")) {
      usage(argv[0]);
      exit(0);
    }
    infile = argv[1];
    break;

  default:
    usage(argv[0]);
    exit(1);
  }


  f = fopen(infile, "r");
  while (1) {
    base = fgetc(f);
    if (base == EOF) {
      break;
    }
    if (state == HDR) {
      putchar(base);
      if (base == '\n') {
	state = SEQ;
      }
    } else {
      if (base == '>') {
	putchar(base);
	state = HDR;
      } else if (base == from) {
	putchar(to);
      } else {
	putchar(base);
      }
    }
  }
  fclose(f);
  exit(0);
}


  
