#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[256];
int top = -1, temp = 1;

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void emit(char op, char a, char b) {
    printf("t%d = %c %c %c\n", temp, a, op, b);
    stack[++top] = (char)('0' + temp);
    temp++;
}

int main(void) {
    char expr[256], out[256];
    int n = 0;
    scanf("%255s", expr);
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isalnum((unsigned char)c)) out[n++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                char op = stack[top--];
                char b = out[--n], a = out[--n];
                emit(op, a, b);
                out[n++] = stack[top];
            }
            if (top >= 0) top--;
        } else {
            while (top >= 0 && prec(stack[top]) >= prec(c)) {
                char op = stack[top--];
                char b = out[--n], a = out[--n];
                emit(op, a, b);
                out[n++] = stack[top];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) {
        char op = stack[top--];
        char b = out[--n], a = out[--n];
        printf("t%d = %c %c %c\n", temp, a, op, b);
        out[n++] = (char)('0' + temp++);
    }
    if (n == 1) printf("Result = %c\n", out[0]);
    return 0;
}
