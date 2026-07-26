%{
#include <stdio.h>
%}

%%
[AEIOUaeiou]
{
    printf("Vowel\n");
}

[a-zA-Z]
{
    printf("Consonant\n");
}

.
{
    printf("Not an Alphabet\n");
}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Character: ");
    yylex();
    return 0;
}