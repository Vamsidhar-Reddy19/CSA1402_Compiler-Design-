%{
#include <stdio.h>
%}

%%
[A-Z]                    { printf("Capital Letter\n"); }

[a-zA-Z_][a-zA-Z0-9_]*
{
    printf("Identifier\n");
}

.
{
    printf("Neither\n");
}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Input: ");
    yylex();
    return 0;
}