#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char line[256], op[8], a[64], b[64], x[64];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        if (!fgets(line, sizeof(line), stdin)) break;
        if (sscanf(line, "%63s = %63s %7s %63s", x, a, op, b) == 4) {
            printf("MOV R0, %s\n", a);
            if (strcmp(op, "+") == 0) printf("ADD R0, %s\n", b);
            else if (strcmp(op, "-") == 0) printf("SUB R0, %s\n", b);
            else if (strcmp(op, "*") == 0) printf("MUL R0, %s\n", b);
            else if (strcmp(op, "/") == 0) printf("DIV R0, %s\n", b);
            printf("MOV %s, R0\n", x);
        } else if (sscanf(line, "%63s = %63s", x, a) == 2) {
            printf("MOV R0, %s\nMOV %s, R0\n", a, x);
        }
    }
    return 0;
}
