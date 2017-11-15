#include <stdio.h>

char* read_word(char* buf, int max_word_length)
{
    char c;
    int i;
    for (i = 0; i < max_word_length && (c = getchar()) != EOF && c != '\n'; ) {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return buf;
}

#define WORD_LIMIT 20

int main()
{
    char buf[WORD_LIMIT + 1] = {0};
    read_word(buf, WORD_LIMIT);
    printf("%s", buf);
    return 0;
}
