#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[2048];
    int count = 0;
    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i]; i++) {
        int c = tolower((unsigned char)s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    printf("Vowels: %d\n", count);
    return 0;
}
