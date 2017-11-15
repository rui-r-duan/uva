#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 72
#define MAX_K 20
#define MAX_E 20
#define MAX_L 20

/* int stricmp(const char *a, const char *b) */
/* { */
/* 	for (; tolower(*a) == tolower(*b); ++a, ++b) { */
/* 		if (*a == '\0') */
/* 			return 0; */
/* 	} */
/* 	return (tolower(*(unsigned char *)a) < tolower(*(unsigned char *)b) ? -1 : +1); */
/* } */

int main()
{
	char keys[MAX_K][MAX_L];
	char excuses[MAX_E][MAX_LINE];
	char exc[MAX_LINE];			/* copy of an excuse, used for strtok */
	int  incidences[MAX_E];
	int  marks_for_largest[MAX_E]; /* largest one mark 1, otherwise mark 0 */
	/* char delimiters[] = " \",.!?0123456789"; */
    char delimiters[] = " ";
	int k;						/* number of keys */
	int e;						/* number of excuses */
	int ki;
	int ei;
	int maxcount;
	int ret;
	int set_count = 0;

	
	while ((ret = scanf("%d %d\n", &k, &e)) != EOF) {
		set_count++;
		memset(incidences, 0, MAX_E * sizeof(int));

		for (ki = 0; ki < k; ki++) {
			gets(keys[ki]);
			/* printf("%s\n", keys[ki]); */
		}

		for (ei = 0; ei < e; ei++) {
			char *s = NULL;
			gets(excuses[ei]);
			/* printf("%s\n", excuses[ei]); */
			strcpy(exc, excuses[ei]);
            for (s = exc; *s != '\0'; s++) {
                if (isalpha(*s)) {
                    *s = tolower(*s);
                } else {
                    *s = ' ';
                }
            }
			for (s = exc;
				 (s = strtok(s, delimiters)) != NULL;
				 s = NULL) {
				/* printf("%s\n", s); */
				for (ki = 0; ki < k; ki++) {
					if (0 == strcmp(keys[ki], s)) {
						incidences[ei]++;
					}
				}
			}
		}

		maxcount = incidences[0];
		for (ei = 1; ei < e; ei++) {
			if (incidences[ei] > maxcount) {
				maxcount = incidences[ei];
			}
		}
		/* printf("maxcount = %d\n", maxcount); */

		for (ei = 0; ei < e; ei++) {
			if (incidences[ei] == maxcount) {
				marks_for_largest[ei] = 1;
			} else {
				marks_for_largest[ei] = 0;
			}
		}
		/* for (ei = 0; ei < e; ei++) { */
		/* 	printf("%d ", marks_for_largest[ei]); */
		/* } */
		/* putchar('\n'); */

		printf("Excuse Set #%d\n", set_count);
		for (ei = 0; ei < e; ei++) {
			if (marks_for_largest[ei]) {
				printf("%s\n", excuses[ei]);
			}
		}
		putchar('\n');
	}

	return 0;
}
