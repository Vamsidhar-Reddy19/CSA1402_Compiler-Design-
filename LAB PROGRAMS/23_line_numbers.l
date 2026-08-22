%{
#include <stdio.h>
int line = 1;
%}
%%
\n      { printf("\n%4d ", ++line); }
.       { ECHO; }
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    printf("%4d ", line);
    yylex();
    return 0;
}
int yywrap(void) { return 1; }
