%{
#include <stdio.h>
#include <string.h>
char longest[256] = "";
%}
%%
[A-Za-z]+ {
    if (yyleng > (int)strlen(longest)) {
        strncpy(longest, yytext, sizeof(longest) - 1);
        longest[sizeof(longest) - 1] = '\0';
    }
}
.|\n ;
%%
int main(void) {
    yylex();
    printf("Longest word: %s\nLength: %zu\n", longest, strlen(longest));
    return 0;
}
int yywrap(void) { return 1; }
