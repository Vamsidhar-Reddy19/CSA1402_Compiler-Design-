%{
#include <stdio.h>
%}
%%
[0-9]+(\.[0-9]+)? { printf("Number: %s\n", yytext); }
[()+\-*/%]        { printf("Operator: %s\n", yytext); }
[ \t\r\n]+        ;
.                 { printf("Invalid symbol: %s\n", yytext); }
%%
int main(void) { yylex(); return 0; }
int yywrap(void) { return 1; }
