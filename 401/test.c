#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

char g_line[MAX_LINE];
const char ta[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char tb[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

__inline size_t char_index(char c)
{
    return isupper(c) ? (c - 'A') : (c - '1' + 26);
}

__inline char mirror(char c)
{
    return tb[char_index(c)];
}

int is_mirror(const char *s)
{
    size_t i = 0;
    size_t j = strlen(s) - 1; /* size_t causes problem!!!! 0 - 1 = max size_t */

    while (i <= j) {            /* <= */
        printf("i = %u, j = %u\ns[i] = %c, s[j] = %c, mirror(s[j]) = %c\n",
               i, j, s[i], s[j], mirror(s[j]));
        if (s[i] == mirror(s[j])) {
            i++;
            j--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i;
    /* for (i = 0; i < 35; ++i) { */
    /*     printf("%c - %c\n", ta[i], mirror(ta[i])); */
    /* } */
    if (is_mirror("A"))
        printf("A is a mirror string.\n");
    printf("mirror('2') = %c\n", mirror('2'));
    return 0;
}
