#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

char line1[MAX_LINE];
char line2[MAX_LINE];

/* if begin == end, the string is null */
typedef struct LightStr_ {
  char *begin;
  char *end;			/* point to the one off the end */
} LightStr;

void print_lightstr(LightStr s);

int main()
{
  int n;
  int i;
  LightStr s[6];

  scanf("%d\n", &n);

  for (i = 0; i < n; ++i) {
    int j;
    char *src;

    if (fgets(line1, MAX_LINE, stdin) == NULL) {
      return 1;
    }
    if (fgets(line2, MAX_LINE, stdin) == NULL) {
      return 1;
    }

    for (j = 1, src = &line1[0]; j <= 5; ++j, src++) {
      char end_symb = (j % 2) == 1 ? '<' : '>';

      s[j].begin = src;
      while (*src && *src != end_symb) {
	src++;
      }
      s[j].end = src;
    }

    /* print out new line1 */
    for (j = 1; j <= 5; ++j) {
      print_lightstr(s[j]);
    }

    /* print out new line2 */
    s[0].begin = line2;
    s[0].end = strchr(line2, '.');
    print_lightstr(s[0]);
    print_lightstr(s[4]);
    print_lightstr(s[3]);
    print_lightstr(s[2]);
    print_lightstr(s[5]);
  }

  return 0;
}

void print_lightstr(LightStr s)
{
  char *p = NULL;

  for (p = s.begin; p != s.end; ++p) {
    putchar(*p);
  }
}
