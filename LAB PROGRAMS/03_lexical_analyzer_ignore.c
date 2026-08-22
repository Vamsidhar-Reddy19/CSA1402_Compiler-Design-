#include <stdio.h>

int main(void) {
    int c, next;
    int line_comment = 0, block_comment = 0;
    while ((c = getchar()) != EOF) {
        if (line_comment) {
            if (c == '\n') line_comment = 0;
            continue;
        }
        if (block_comment) {
            if (c == '*') {
                next = getchar();
                if (next == '/') block_comment = 0;
                else if (next != EOF) ungetc(next, stdin);
            }
            continue;
        }
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') continue;
        if (c == '/') {
            next = getchar();
            if (next == '/') {
                line_comment = 1;
                continue;
            }
            if (next == '*') {
                block_comment = 1;
                continue;
            }
            if (next != EOF) ungetc(next, stdin);
        }
        putchar(c);
    }
    return 0;
}
