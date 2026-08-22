#include <stdio.h>

int main(void) {
    char op;
    scanf(" %c", &op);
    if (op == '+' || op == '-' || op == '*' || op == '/')
        printf("Valid arithmetic operator\n");
    else
        printf("Invalid arithmetic operator\n");
    return 0;
}
