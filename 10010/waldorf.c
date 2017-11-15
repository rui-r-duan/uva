#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct _LetterGrid
{
    int m;
    int n;
    char grid[51][51];
} LetterGrid;

void find_word(const LetterGrid *pg, const char *word, int *row, int *col);
int is_equal_char_ci(char a, char b);

int main()
{
    int count;
    LetterGrid g;
    int k;
    char word[1024];

    memset(&g, 0, sizeof(LetterGrid));

    scanf("%d", &count);

    while (count) {
        int i;
        int row = 0;
        int col = 0;

        scanf("%d", &g.m);
        scanf("%d", &g.n);

        for (i = 0; i < g.m; ++i) {
            scanf("%s", g.grid[i]);
        }

        scanf("%d", &k);
        while (k) {
            scanf("%s", word);
            find_word(&g, word, &row, &col);
            printf("%d %d\n", row, col);
            --k;
        }

        --count;

        if (count) {
            putchar('\n');
        }
    }

    return 0;
}

void find_word(const LetterGrid *pg, const char *word, int *row, int *col)
{
    /* move mode k: row += drow[k], col += dy[k] */
    const int drow[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
    const int dcol[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
    int i, j;
    int k;                      /* move mode index */

    for (i = 0; i < pg->m; ++i) {   /* line iteration */
        for (j = 0; j < pg->n; ++j) { /* column iteration */
            char c = pg->grid[i][j];
            if (is_equal_char_ci(c, word[0])) {
                for (k = 0; k < 8; ++k) {
                    int new_row = i;
                    int new_col = j;
                    int move_count = 0;
                    while (1) {
                        char nc; /* next char */

                        /*
                         * This checking for end of word must go before
                         * the bound checking in the grid.
                         */
						++move_count;
                        if ('\0' == word[move_count]) {
                            *row = i + 1;
                            *col = j + 1;
                            return;
                        }

                        new_row += drow[k];
                        new_col += dcol[k];
                        if (new_row >= pg->m || new_col >= pg->n ||
                            new_row < 0 || new_col < 0) {
                            break;
                        }
                        nc = pg->grid[new_row][new_col];

                        if (!is_equal_char_ci(nc, word[move_count])) {
                            break;
                        }
                    }
                }
            }
        }
    }
}

int is_equal_char_ci(char a, char b)
{
    char c = tolower(a);
    char d = tolower(b);
    return c == d;
}
