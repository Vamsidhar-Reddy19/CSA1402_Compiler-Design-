#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char s[128];
    int valid = 1;
    scanf("%127s", s);
    if (!(isalpha((unsigned char)s[0]) || s[0] == '_')) valid = 0;
    for (size_t i = 1; s[i] && valid; i++)
        if (!(isalnum((unsigned char)s[i]) || s[i] == '_')) valid = 0;
    printf("%s\n", valid ? "Valid identifier" : "Invalid identifier");
    return 0;
}
