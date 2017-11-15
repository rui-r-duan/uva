// Input:
// A maximum of 100 sentences, each not exceeding 100 characters long.
// Leagal characters: newline, space, any punctuation characters, digits, and
// lower case or upper case English letters.
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    char a[101][101];
    int total_lines = 0;
    int i, j;

    // Assign blank spaces.
    for (i = 0; i < 101; i++) {
        for (j = 0; j < 101; j++) {
            a[i][j] = ' ';
        }
    }

    // Take all the inputs.
    while (gets(a[total_lines]))
        total_lines++;

    // Find the max length.
    int max = 0;
    int length;
    for (i = 0; i < total_lines; i++) {
        length = strlen(a[i]);
        if (length > max)
            max = length;
        a[i][length] = ' ';
    }

    // Output.
    for (i = 0; i < max; i++) {
        for (j = total_lines - 1; j >= 0; j--) {
            printf("%c", a[j][i]);
        }
        putchar('\n');
    }
    return 0;
}
