%{
#include <stdio.h>
%}
%%
"#include"[ \t]*<[^>\n]+>       { printf("Header: %s\n", yytext); }
"int"|"char"|"float"|"double"|"void"|"if"|"else"|"for"|"while"|"return" {
    printf("Keyword: %s\n", yytext);
}
\"([^\"\\]|\\.)*\"              { printf("String: %s\n", yytext); }
[A-Za-z_][A-Za-z0-9_]*          { printf("Identifier: %s\n", yytext); }
[0-9]+(\.[0-9]+)?               { printf("Constant: %s\n", yytext); }
"=="|"!="|"<="|">="|"++"|"--"|"&&"|"||"|"="|"+"|"-"|"*"|"/"|"<"|">" {
    printf("Operator: %s\n", yytext);
}
[(){}\[\],;.]                   { printf("Delimiter: %s\n", yytext); }
[ \t\r\n]+                       ;
.                                { printf("Unknown: %s\n", yytext); }
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    return 0;
}
int yywrap(void) { return 1; }
