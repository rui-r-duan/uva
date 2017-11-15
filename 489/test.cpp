#include <iostream>
#include <cstdio>
using namespace std;

inline size_t char_index(int c)
{
    return c - 'a';
}

int main()
{
    int c = getchar();         // ñ (\303, #xC3)
    putchar(c);
    printf("%d\n", char_index(c));
    putchar('a' + char_index(c));
    putchar('\n');
    return 0;
}
