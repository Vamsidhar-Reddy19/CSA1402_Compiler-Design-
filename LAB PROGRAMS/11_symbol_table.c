#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    char type[32];
    char value[64];
} Symbol;

Symbol table[100];
int n = 0;

void insert(void) {
    if (n >= 100) return;
    scanf("%63s %31s %63s", table[n].name, table[n].type, table[n].value);
    for (int i = 0; i < n; i++)
        if (strcmp(table[i].name, table[n].name) == 0) {
            printf("Duplicate symbol\n");
            return;
        }
    n++;
    printf("Inserted\n");
}

void search(void) {
    char name[64];
    scanf("%63s", name);
    for (int i = 0; i < n; i++)
        if (strcmp(table[i].name, name) == 0) {
            printf("%s %s %s\n", table[i].name, table[i].type, table[i].value);
            return;
        }
    printf("Not found\n");
}

void display(void) {
    printf("Name\tType\tValue\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%s\t%s\n", table[i].name, table[i].type, table[i].value);
}

int main(void) {
    int choice;
    do {
        printf("1.Insert 2.Search 3.Display 4.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) insert();
        else if (choice == 2) search();
        else if (choice == 3) display();
    } while (choice != 4);
    return 0;
}
