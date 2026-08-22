%{
#include <stdio.h>
int macros = 0, headers = 0;
%}
%%
^[ \t]*#[ \t]*define[ \t]+[A-Za-z_][A-Za-z0-9_]*   { macros++; }
^[ \t]*#[ \t]*include[ \t]*[<"][^>"]+[>"]             { headers++; }
([0-9]+\.[0-9]+|[0-9]+)                              { printf("Constant: %s\n", yytext); }
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    printf("Macros: %d\nHeaders: %d\n", macros, headers);
    return 0;
}
int yywrap(void) { return 1; }
