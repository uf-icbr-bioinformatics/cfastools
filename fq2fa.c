#include <stdio.h>
#include <string.h>

#define SIZE 100000

char buf[SIZE];

void main(int argc, char* argv[]) {
  char *x;
  char o;
  int names = 1;
  int seqs = 1;

  //printf("%d %\n", argc);
  if (argc == 2) {
    if (strlen(argv[1]) == 2) {
      o = argv[1][1];
      //printf("%c\n", o);
      switch (o) {
      case 'h':
	printf("Usage: fq2fa [-h] [-n] [-s]\n\n");
	printf("Reads a fastq file from standard input, and writes the corresponding fasta file to standard output.\n\n");
	printf("Options:\n\n  -h | Print this help message\n  -n | Output sequence names only\n  -s | Output sequences only\n\n");
	return;
	break;
      case 'n':
	seqs = 0;
	break;
      case 's':
	names = 0;
	break;
      }
    }
  }

  //printf("%d %d\n", names, seqs);

  while (1) {
    x = fgets(buf, SIZE, stdin);
    if (x == NULL) {
      return;
    }
    buf[0] = '>';
    if (names == 1) {
      printf(buf);
    }
    fgets(buf, SIZE, stdin);
    if (seqs == 1) {
      printf(buf);
    }
    fgets(buf, SIZE, stdin);
    fgets(buf, SIZE, stdin);
  }
}
