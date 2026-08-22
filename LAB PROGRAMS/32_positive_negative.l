%{
#include <stdio.h>
int positive = 0, negative = 0;
%}
%%
-[0-9]+    { negative++; printf("Negative: %s\n", yytext); }
\+[0-9]+   { positive++; printf("Positive: %s\n", yytext); }
[0-9]+     { positive++; printf("Positive: %s\n", yytext); }
[ \t\r\n]+ ;
. ;
%%
int main(void) {
    yylex();
    printf("Positive count: %d\nNegative count: %d\n", positive, negative);
    return 0;
}
int yywrap(void) { return 1; }
