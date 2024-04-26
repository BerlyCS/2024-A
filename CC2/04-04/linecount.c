#include <stdio.h>

/* count lines in input */
int main() {
    int c, n1;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++n1;
    }
    printf("%d\n",n1);
}
