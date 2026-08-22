CSA14 Compiler Design - 40 Experiments

The folder contains exactly 40 source files corresponding to experiments 1 through 40 in the supplied experiment list.

C programs:
01-18, 21, 30

LEX/FLEX programs:
19, 20, 22-29, 31-40

C compilation:
gcc filename.c -o program

LEX/FLEX compilation:
flex filename.l
gcc lex.yy.c -o program

Most LEX/FLEX programs accept standard input. Programs that support a filename accept it as a command-line argument.
