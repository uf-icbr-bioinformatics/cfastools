#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

char buf[SIZE];

void usage() {
  fprintf(stderr, "Usage: fqsample OFFSET NDIST\n");
  fprintf(stderr, "\nWrites one read every NDIST from a fastq file passed as stdin\n");
  fprintf(stderr, "starting at read OFFSET. For example:\n\n");
  fprintf(stderr, "  fqsample 2 5\n\n");
  fprintf(stderr, "will write reads #2, #7, #12, etc.\n\n");
}

void main(int argc, char* argv[]) {
  int i, offset, ndist;
  char *x;

  if (argc < 3) {
      usage();
      exit(1);
    }

  /* printf("args: %s %s\n", argv[1], argv[2]); */

  offset = (atoi((char *)argv[1]) - 1) * 4;
  /* fprintf(stderr, "Skipping %d lines.\n", offset); */

  ndist = (atoi((char *)argv[2]) - 1) * 4;
  /* fprintf(stderr, "Step = %d\n", ndist); */

  for (i = 0; i < offset; i++) {
    fgets(buf, SIZE, stdin);
  }

  while (1) {
    for (i = 0; i < 4; i++) {
      x = fgets(buf, SIZE, stdin);
      if (x == NULL) {
	return;
      }
      printf(buf);
    }
    for (i = 0; i < ndist; i++) {
      x = fgets(buf, SIZE, stdin);
    }
  }
}
