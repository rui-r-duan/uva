#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;

int main()
{
    char input_digits[132] = { 0 };
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            input_digits[i++] = c - '0';
        } else if (isalpha(c) || '*' == c) {
            int n = 0;
            int j, k;
            for (j = 0; j < i; ++j) {
                n += input_digits[j];
                input_digits[j] = 0;
            }
            i = 0;
            if ('b' == c) {
                for (k = 0; k < n; ++k) {
                    putchar(' ');
                }
            } else {
                for (k = 0; k < n; ++k) {
                    putchar(c);
                }
            }
        } else if ('!' == c || '\n' == c) {
            putchar('\n');
        }
    }
    return 0;
}
