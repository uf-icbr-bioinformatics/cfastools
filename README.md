# cfastools
## Small C utilities for fasta/fastq files

This repository contains three simple C programs to operate on files in fasta and
fastq format.

## fq2fa
Converts a fastq file (read from standard input) to fasta format (written to standard output). If the `-n` option is supplied, only outputs sequence names. If the `-s` option is supplied, only outputs sequences (one per line).

## fqsample
Reads a fastq file from standard output and outputs a subset of the reads according to the supplied OFFSET and NDIST arguments (where OFFSET is between 0 and NDIST-1). In each block of NDIST reads, only the one numbered OFFSET will be output. This command is useful to distribute reads from a fastq file into several different files in round-robin fashion.

## faconvert
Reads a fasta file and outputs a copy replacing all Cs with Ts. A different replacement can be specified using the second argument, indicating the "from" and "to" bases. For example, to replace Gs with As, use: `faconvert infile.fa GA`.

## Help
Calling these programs with the `-h` option prints a simple usage message.

## Compilation
These are stand-alone C programs with no dependencies, so they can be compiled with a simple gcc command, e.g.:

```
gcc faconvert.c -o faconvert
```
