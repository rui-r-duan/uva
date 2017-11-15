#include <stdio.h>

int main()
{
    char s[120];
    int i = 2;
    while (i) {
        scanf("%s", s);
        printf("\n%s", s);
        --i;
    }

    return 0;
}
