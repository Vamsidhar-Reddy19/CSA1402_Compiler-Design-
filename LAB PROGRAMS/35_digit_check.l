%{
#include <stdio.h>
%}
%%
[0-9]   { printf("%s is a digit\n", yytext); }
[^ \t\r\n] { printf("%s is not a digit\n", yytext); }
[ \t\r\n]+ ;
%%
int main(void) { yylex(); return 0; }
int yywrap(void) { return 1; }
