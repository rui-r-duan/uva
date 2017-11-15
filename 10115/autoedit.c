#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_WORD_CHARS 81
#define MAX_LINE_CHARS 81
#define MAX_TEMP_LINE_CHARS 256

typedef struct Rule_ {
    char szfind[MAX_WORD_CHARS];
    char szrepl[MAX_WORD_CHARS];
} Rule;

/* ================ GLOBAL VARIABLES ================ */
Rule rules[MAX_RULES];
int rulecount;
char line[MAX_LINE_CHARS];
char temp[MAX_TEMP_LINE_CHARS];

static int mygetline(char s[]);
static char *str_repl_all(char *line, const char *find, const char *replace_by);

int
main()
{
    int i;
    while (scanf("%d\n", &rulecount) != EOF) {
        if (rulecount == 0) {
            break;
        }

        for (i = 0; i < rulecount; ++i) {
            mygetline(rules[i].szfind);
            mygetline(rules[i].szrepl);
        }
        mygetline(line);

        strcpy(temp, line);
        for (i = 0; i < rulecount; ++i) {
            str_repl_all(temp, rules[i].szfind, rules[i].szrepl);
        }
        strcpy(line, temp);

        printf("%s\n", line);
    }
    return 0;
}

int
mygetline(char s[])
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

char *
str_repl_all(char *line, const char *find, const char *replace_by)
{
    char *p = NULL;
    char *q = NULL;
    char *r = NULL;
    size_t len_find = strlen(find);
    size_t len_repl = strlen(replace_by);

    while ((p = strstr(line, find)) != NULL) {
        /* Move the tail string (start at q) behind to r. */
        if (len_find != len_repl) {
            q = p + len_find;
            r = p + len_repl;
            size_t len = strlen(q);
            memmove(r, q, len + 1); /* +1 means move ending '\0' */
        }

        /* Copy string replace_by to q, do not copy the ending '\0'. */
        memcpy(p, replace_by, len_repl);
    }
    return line;
}
