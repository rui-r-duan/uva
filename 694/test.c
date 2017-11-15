#include <stdio.h>

int main()
{
    int a, b;
    while (!feof(stdin)) {
        if (scanf("%d", &a) == EOF)
            return 0;
        if (scanf("%d", &b) == EOF)
            return 0;
        printf("%d %d\n", a, b);
    }
    return 0;
}
