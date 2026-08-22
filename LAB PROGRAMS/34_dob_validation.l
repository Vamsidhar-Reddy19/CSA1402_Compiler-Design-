%{
#include <stdio.h>
%}
%%
(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4} {
    printf("Valid DOB format: %s\n", yytext);
}
[0-9]{1,2}/[0-9]{1,2}/[0-9]{4} {
    printf("Invalid DOB format: %s\n", yytext);
}
[ \t\r\n]+ ;
. ;
%%
int main(void) { yylex(); return 0; }
int yywrap(void) { return 1; }
