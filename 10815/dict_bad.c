#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 202
#define MAX_WORDS 5000

void preprocess_line(char *line);
int  find_insert_point(char (*dict)[MAX_LINE], const char *word);
int  add_to_dict(char (*dict)[MAX_LINE], const char *word);
void print_dict(char (*dict)[MAX_LINE]);

int main()
{
    char line[MAX_LINE];
    char *s;
    char dict[MAX_WORDS][MAX_LINE];

    memset(&dict[0][0], 0, MAX_WORDS * MAX_LINE * sizeof(char));

    while (fgets(line, MAX_LINE, stdin)) {
        preprocess_line(line);
        for (s = line; (s = strtok(s, " ")) != NULL; s = NULL) {
            (void)add_to_dict(dict, s);
        }
    }

    print_dict(dict);

    return 0;
}

void
preprocess_line(char *line)
{
    while (*line) {
        *line = tolower(*line);
        if (!isalpha(*line)) {
            *line = ' ';
        }
        line++;
    }
}

/* @return: -1 indicates the word is already in the dict, do not need insert
 *          -2 indicates the dict is full, no space for insertion.
 */
int
find_insert_point(char (*dict)[MAX_LINE], const char *word)
{
    int i;
    for (i = 0; i < MAX_WORDS; ++i) {
        int r;
        if (dict[i][0] == '\0') {
            return i;
        }

        r = strcmp(dict[i], word);
        if (r > 0) {
            return i;
        }
        else if (r == 0) {
            return -1;
        }
        else {
            continue;
        }
    }
    return -2;
}

int
add_to_dict(char (*dict)[MAX_LINE], const char *word)
{
    int i;
    i = find_insert_point(dict, word);
    if (i != -1 && i != -2) {
        strcpy(dict[i], word);
    }
    return 0;
}

void
print_dict(char (*dict)[MAX_LINE])
{
    int i;
    for (i = 0; i < MAX_WORDS; ++i) {
        if (dict[i][0]) {
            printf("%s\n", dict[i]);
        }
        else {
            break;
        }
    }
}
