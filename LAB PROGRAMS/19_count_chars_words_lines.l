%{
#include <stdio.h>
long characters = 0, words = 0, lines = 0;
%}
%%
\n              { characters++; lines++; }
[ \t\r\f\v]+    { characters += yyleng; }
[^ \t\r\n\f\v]+ { characters += yyleng; words++; }
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    printf("Characters: %ld\nWords: %ld\nLines: %ld\n", characters, words, lines);
    return 0;
}
int yywrap(void) { return 1; }
