#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 202

char d[100010][MAX_LINE];
int n;
int len;

int cmp_str(const void *a, const void *b)
{
    return strcmp((const char*)a, (const char*)b);
}

int main()
{
    int c;
    int i;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            d[n][len++] = tolower(c);
        }
        else {
            if (isalpha(d[n][0])) {
                d[n][len] = '\0';
                len = 0;
                n++;
            }
        }
    }

    qsort(d, n, sizeof(d[0]), cmp_str);

    for (i = 0; i < n; ++i) {
        if (strcmp(d[i], d[i+1])) {
            printf("%s\n", d[i]);
        }
    }

    return 0;
}
