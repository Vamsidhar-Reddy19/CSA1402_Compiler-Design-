#include <stdio.h>
#include <string.h>

int main(void) {
    const char *set[] = {"(", "id"};
    const char *nt[] = {"E", "T", "F"};
    for (int i = 0; i < 3; i++) {
        printf("LEADING(%s) = { %s, %s }\n", nt[i], set[0], set[1]);
    }
    return 0;
}
