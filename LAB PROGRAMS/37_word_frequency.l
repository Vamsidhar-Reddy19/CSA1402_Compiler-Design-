%{
#include <stdio.h>
#include <string.h>
int count = 0;
char target[128] = "word";
%}
%%
[A-Za-z]+ {
    if (strcasecmp(yytext, target) == 0) count++;
}
.|\n ;
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        strncpy(target, argv[1], sizeof(target) - 1);
        target[sizeof(target) - 1] = '\0';
    }
    yylex();
    printf("Frequency of %s: %d\n", target, count);
    return 0;
}
int yywrap(void) { return 1; }
