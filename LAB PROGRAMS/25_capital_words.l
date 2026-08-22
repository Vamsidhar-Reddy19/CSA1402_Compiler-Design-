%{
#include <stdio.h>
%}
%%
\b[A-Z][A-Z0-9_]*\b   { printf("Capital word: %s\n", yytext); }
[A-Za-z0-9_]+         ;
.|\n                  ;
%%
int main(void) { yylex(); return 0; }
int yywrap(void) { return 1; }
