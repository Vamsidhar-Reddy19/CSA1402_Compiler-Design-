#include <stdio.h>
#include <ctype.h>

char input[256];
int pos = 0;

int E(void);
int T(void);
int F(void);

int E(void) {
    if (!T()) return 0;
    while (input[pos] == '+') {
        pos++;
        if (!T()) return 0;
    }
    return 1;
}

int T(void) {
    if (!F()) return 0;
    while (input[pos] == '*') {
        pos++;
        if (!F()) return 0;
    }
    return 1;
}

int F(void) {
    if (isalnum((unsigned char)input[pos])) {
        pos++;
        return 1;
    }
    if (input[pos] == '(') {
        pos++;
        if (!E() || input[pos] != ')') return 0;
        pos++;
        return 1;
    }
    return 0;
}

int main(void) {
    scanf("%255s", input);
    printf("%s\n", E() && input[pos] == '\0' ? "Valid" : "Invalid");
    return 0;
}
