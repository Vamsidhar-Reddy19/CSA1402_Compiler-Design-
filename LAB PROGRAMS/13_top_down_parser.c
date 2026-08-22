#include <stdio.h>

char s[256];
int pos;

int S(void) {
    if (s[pos] == 'a') {
        pos++;
        if (S()) {
            if (s[pos] == 'b') {
                pos++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 1;
}

int main(void) {
    scanf("%255s", s);
    pos = 0;
    printf("%s\n", S() && s[pos] == '\0' ? "String accepted" : "String rejected");
    return 0;
}
