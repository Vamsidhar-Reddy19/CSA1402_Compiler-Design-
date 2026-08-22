%{
#include <stdio.h>
%}
%%
[6-9][0-9]{9}   { printf("Valid mobile number: %s\n", yytext); }
[0-9]+          { printf("Invalid mobile number: %s\n", yytext); }
[ \t\r\n]+      ;
.               { printf("Invalid input: %s\n", yytext); }
%%
int main(void) { yylex(); return 0; }
int yywrap(void) { return 1; }
