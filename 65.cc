#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 33

typedef struct Stack {
    char a[500][MAX];
    int t;
} Stack;

void push(Stack *s, char *o) {
    strcpy(s->a[++s->t], o);
}

char *pop(Stack *s) {
    return s->a[s->t--];
}

char *find(char *s, char a[50][2][MAX], int c) {
    for (int i = 0; i < c; i++) {
        if (!strcmp(a[i][0], s)) {
            return a[i][1];
        }
    }
}

int main() {
    int c = 0;
    char a[50][2][MAX], b[1001], v[MAX], x[MAX], y[MAX];

    fgets(b, 1001, stdin);
    b[strcspn(b, "\n")] = 0;
    while (scanf("%s = %s", x, y) == 2) {
        strcpy(a[c][0], x);
        strcpy(a[c++][1], y);
    }
    Stack *s = malloc(sizeof(Stack));
    s->t = -1;
    for (char *p = strtok(b, " "); p; p = strtok(0, " ")) {
        if (*p == ' ' || *p == '(') {
            continue;
        } else if (*p == ')') {
            strcpy(y, pop(s));
            if (*y != '-' && (*y < '0' || *y > '9')) {
                strcpy(y, find(y, a, c));
            }
            strcpy(x, pop(s));
            if (*x != '-' && (*x < '0' || *x > '9')) {
                strcpy(x, find(x, a, c));
            }
            strcpy(v, pop(s));
            if (*v == '+') {
                sprintf(s->a[++s->t], "%ld", strtol(x, 0, 10) + strtol(y, 0, 10));
            } else if (*v == '-') {
                sprintf(s->a[++s->t], "%ld", strtol(x, 0, 10) - strtol(y, 0, 10));
            } else if (*v == '*') {
                sprintf(s->a[++s->t], "%ld", strtol(x, 0, 10) * strtol(y, 0, 10));
            } else if (*v == '/') {
                sprintf(s->a[++s->t], "%ld", strtol(x, 0, 10) / strtol(y, 0, 10));
            }
        } else {
            push(s, p);
        }
    }
    printf("%s\n", pop(s));
    return 0;
}
