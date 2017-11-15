#include <stdio.h>
#include <string.h>

/* MAX_BITS includes the '\0' */
#define MAX_BITS 11
#define MAX_CODES 8

typedef char Code[MAX_BITS];

#define COLLECT_COMPLETE 1
#define COLLECT_CONT     0
int collect_code(Code *ps, char bit);

#define TRUE  1
#define FALSE 0
int is_immediately_decodable(Code codes[]);

/* ================ GLOBAL VARIABLES ================ */
Code s[MAX_CODES];
int codecount;

int
main()
{
	char c;
	int bDecodable = FALSE;
	int setcount = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			continue;			/* ready to start next code set */
		}

		do {
			if (collect_code(&s[codecount], c) == COLLECT_COMPLETE) {
				codecount++;
			}
		} while ((c = getchar()) != '9');

		setcount++;

		bDecodable = is_immediately_decodable(s);
		printf("Set %d is ", setcount);
		if (bDecodable) {
			printf("immediately decodable\n");
		}
		else {
			printf("not immediately decodable\n");
		}

		/* Prepare for next code set */
		codecount = 0;
	}
	return 0;
}

int
collect_code(Code *ps, char c)
{
	static int j = 0;

	if (c != '\n') {
		(*ps)[j++] = c;
		return COLLECT_CONT;
	}
	else {
		(*ps)[j] = '\0';
		j = 0;
		return COLLECT_COMPLETE;
	}
}

int
is_immediately_decodable(Code codes[])
{
	int i;
	int j;
	/* for (i = 0; i < codecount; ++i) { */
	/* 	printf("%s\n", codes[i]); */
	/* } */
	for (i = 0; i < codecount; ++i) {
		for (j = i + 1; j < codecount; ++j) {
			if (strstr(codes[i], codes[j]) == codes[i])
				return FALSE;
			if (strstr(codes[j], codes[i]) == codes[j])
				return FALSE;
		}
	}
	return TRUE;
}
