#include <stdio.h>
#include <string.h>

#define N 3
#define T 5

int main(void) {
    char first[N][T][8] = {{{0}}};
    int count[N] = {0};
    const char *names[] = {"S", "A", "B"};

    strcpy(first[1][count[1]++], "epsilon");
    strcpy(first[2][count[2]++], "epsilon");
    strcpy(first[0][count[0]++], "a");
    strcpy(first[0][count[0]++], "b");

    for (int i = 0; i < N; i++) {
        printf("FIRST(%s) = { ", names[i]);
        for (int j = 0; j < count[i]; j++) printf("%s%s", j ? ", " : "", first[i][j]);
        printf(" }\n");
    }
    return 0;
}
