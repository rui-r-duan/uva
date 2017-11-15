#include <stdio.h>

#define MAX_LINE 20

int is_border(const char *line);
unsigned int get_ascci_from_line(const char *line);
/* unsigned int bin_str_to_ascci(const char *binstr); */
/* void get_binstr_from_line(char *binstr, const char *line); */

int
main()
{
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, stdin)) {
	if (!is_border(line)) {
	    int c = get_ascci_from_line(line);
	    putchar(c);
	}
    }

    return 0;
}

__inline int
is_border(const char *line)
{
    return line[0] == '_';
}

unsigned int
get_ascci_from_line(const char *line)
{
    unsigned int c = 0;
    int n = 0;
    while (*line) {
	if (*line == 'o') {
	    n++;
	    c |= 1 << (8 - n);
	} else if (*line == ' ') {
	    n++;
	} else {
	}
	line++;
    }
    return c;
}

/* unsigned int */
/* bin_str_to_ascci(const char *binstr) */
/* { */
/*     unsigned int c = 0; */
/*     int n = 8; */
/*     while (n--) { */
/* 	if (binstr[n] == '1') { */
/* 	    c |= 1 << (8 - n - 1); */
/* 	} */
/*     } */
/*     return c; */
/* } */

/* void */
/* get_binstr_from_line(char *binstr, const char *line) */
/* { */
/*     while (*line) { */
/* 	if (*line == 'o') { */
/* 	    *binstr++ = '1'; */
/* 	} else if (*line == ' ') { */
/* 	    *binstr++ = '0'; */
/* 	} else { */
/* 	} */
/* 	line++; */
/*     } */
/* } */
