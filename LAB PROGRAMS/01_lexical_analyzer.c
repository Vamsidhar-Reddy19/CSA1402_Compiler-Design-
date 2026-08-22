#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    char token[128];
    while ((c = getchar()) != EOF) {
        if (isspace(c)) continue;
        if (isalpha(c) || c == '_') {
            int i = 0;
            do {
                if (i < 127) token[i++] = (char)c;
                c = getchar();
            } while (c != EOF && (isalnum(c) || c == '_'));
            token[i] = '\0';
            printf("Identifier: %s\n", token);
            if (c != EOF) ungetc(c, stdin);
        } else if (isdigit(c)) {
            int i = 0;
            do {
                if (i < 127) token[i++] = (char)c;
                c = getchar();
            } while (c != EOF && (isdigit(c) || c == '.'));
            token[i] = '\0';
            printf("Constant: %s\n", token);
            if (c != EOF) ungetc(c, stdin);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int d = getchar();
            if ((c == '+' && d == '+') || (c == '-' && d == '-') ||
                (c == '*' && d == '=') || (c == '/' && d == '=')) {
                printf("Operator: %c%c\n", c, d);
            } else {
                printf("Operator: %c\n", c);
                if (d != EOF) ungetc(d, stdin);
            }
        }
    }
    return 0;
}
