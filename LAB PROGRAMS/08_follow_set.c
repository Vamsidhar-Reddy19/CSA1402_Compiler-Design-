#include <stdio.h>
#include <string.h>

int main(void) {
    const char *followS[] = {"$"};
    const char *followA[] = {"a", "b"};
    const char *followB[] = {"b", "a"};
    printf("FOLLOW(S) = { $ }\n");
    printf("FOLLOW(A) = { a, b }\n");
    printf("FOLLOW(B) = { b, a }\n");
    (void)followS; (void)followA; (void)followB;
    return 0;
}
