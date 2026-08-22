%{
#include <stdio.h>
int comments = 0;
%}
%x BLOCK
%%
"//"[^\n]*       { comments++; }
"/*"             { comments++; BEGIN(BLOCK); }
<BLOCK>"*/"      { BEGIN(INITIAL); }
<BLOCK>\n        { ECHO; }
<BLOCK>.         ;
\n               { ECHO; }
.                { ECHO; }
%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) return 1;
        yyin = fp;
    }
    yylex();
    fprintf(stderr, "Comment lines: %d\n", comments);
    return 0;
}
int yywrap(void) { return 1; }
