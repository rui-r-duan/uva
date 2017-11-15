#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

char line1[MAX_LINE];
char line2[MAX_LINE];
char s[5][512];

int main()
{
    int n;
    int i;
    scanf("%d\n", &n);

    for (i = 0; i < n; ++i) {
        int j;
        char *src;
        char *dst;

        if (fgets(line1, MAX_LINE, stdin) == NULL) {
            return 1;
        }
        if (fgets(line2, MAX_LINE, stdin) == NULL) {
            return 1;
        }

        for (j = 0, src = &line1[0]; j < 5; ++j, src++) {
            char c = '\0';
            char end_symb = (j % 2) == 0 ? '<' : '>';
            if (j == 4) {
                end_symb == '\n';
            }
            dst = &s[j][0];
            memset(dst, 0, 512);
            while (*src && *src != end_symb) {
                c = *src++;
                *dst++ = c;
            }
	}

        /* update line1 */
        dst = line1;
        memset(dst, 0, MAX_LINE);
        for (j = 0; j < 5; ++j) {
            src = &s[j][0];
            while (*dst++ = *src++)
                ;
            dst--;
        }

        /* update line2 */
        dst = strchr(line2, '.');
        src = s[3];
        while (*dst++ = *src++)
            ;
        dst--;
        src = s[2];
        while (*dst++ = *src++)
            ;
        dst--;
        src = s[1];
        while (*dst++ = *src++)
            ;
        dst--;
        src = s[4];
        while (*dst++ = *src++)
            ;
        dst--;

        fputs(line1, stdout);
        fputs(line2, stdout);
    }

    return 0;
}
