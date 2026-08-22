%{
#include <stdio.h>
#include <string.h>
char oldword[128] = "old";
char newword[128] = "new";
%}
%%
[A-Za-z_][A-Za-z0-9_]* {
    if (strcmp(yytext, oldword) == 0) printf("%s", newword);
    else ECHO;
}
.|\n { ECHO; }
%%
int main(int argc, char **argv) {
    if (argc > 2) {
        strncpy(oldword, argv[1], sizeof(oldword) - 1);
        strncpy(newword, argv[2], sizeof(newword) - 1);
        oldword[sizeof(oldword) - 1] = '\0';
        newword[sizeof(newword) - 1] = '\0';
    }
    if (argc > 3) {
        FILE *fp = fopen(argv[3], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    return 0;
}
int yywrap(void) { return 1; }
