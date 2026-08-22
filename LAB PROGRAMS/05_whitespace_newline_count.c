#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c, whitespace = 0, newline = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') newline++;
        if (isspace(c)) whitespace++;
    }
    printf("Whitespace characters: %d\n", whitespace);
    printf("Newline characters: %d\n", newline);
    return 0;
}
