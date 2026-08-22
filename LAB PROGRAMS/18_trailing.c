#include <stdio.h>

int main(void) {
    const char *nt[] = {"E", "T", "F"};
    for (int i = 0; i < 3; i++)
        printf("TRAILING(%s) = { ), id }\n", nt[i]);
    return 0;
}
