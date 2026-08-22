%{
#include <stdio.h>
%}
%%
<[^>]+>     { printf("%s\n", yytext); }
.|\n        ;
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    return 0;
}
int yywrap(void) { return 1; }
