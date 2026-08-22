#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
    FILE *fp = argc > 1 ? fopen(argv[1], "r") : stdin;
    if (!fp) return 1;
    long characters = 0, words = 0, lines = 0;
    int c, inword = 0;
    while ((c = fgetc(fp)) != EOF) {
        characters++;
        if (c == '\n') lines++;
        if (isspace((unsigned char)c)) inword = 0;
        else if (!inword) {
            words++;
            inword = 1;
        }
    }
    printf("Characters: %ld\nWords: %ld\nLines: %ld\n", characters, words, lines);
    if (fp != stdin) fclose(fp);
    return 0;
}
