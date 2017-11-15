#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

char g_line[MAX_LINE];
/*
const char ta[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"; */
const char tb[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int is_palindrome(const char *s)
{
    int i = 0;
    int j = (int)strlen(s) - 1; /* Can't use unsigned integer! */
    while (i < j) {             /* < */
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            return 0;
        }
    }
    return 1;
}

__inline size_t char_index(char c)
{
    if (isupper(c))
        return (c - 'A');
    else if (isdigit(c))
        return (c - '1' + 26);
    else
        return 35;
}

__inline char mirror(char c)
{
    return tb[char_index(c)];
}

int is_mirror(const char *s)
{
    int i = 0;
    int j = strlen(s) - 1;      /* Can't use unsigned integer! */

    while (i <= j) {            /* <= */
        if (s[i] == mirror(s[j])) {
            i++;
            j--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char *s = g_line;
    int p;                      /* is palindrome */
    int m;                      /* is mirror */
    
    while (gets(s) != NULL) {
        p = is_palindrome(s);
        m = is_mirror(s);
        if (p && m) {
            printf("%s -- is a mirrored palindrome.\n", s);
        } else if (m) {
            printf("%s -- is a mirrored string.\n", s);
        } else if (p) {
            printf("%s -- is a regular palindrome.\n", s);
        } else {
            printf("%s -- is not a palindrome.\n", s);
        }
        putchar('\n');
    }
    return 0;
}
