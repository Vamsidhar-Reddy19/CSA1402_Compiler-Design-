#include <stdio.h>
#include <string.h>

int main(void) {
    char line[2048];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    if (strncmp(line, "//", 2) == 0) {
        printf("Comment\n");
        return 0;
    }
    if (strncmp(line, "/*", 2) == 0 && strstr(line + 2, "*/") != NULL) {
        printf("Comment\n");
        return 0;
    }
    printf("Not a comment\n");
    return 0;
}
