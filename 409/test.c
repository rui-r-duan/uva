#include <stdio.h>
#include <assert.h>

int stricmp(const char *a, const char *b)
{
	for (; tolower(*a) == tolower(*b); ++a, ++b) {
		if (*a == '\0')
			return 0;
	}
	return (tolower(*(unsigned char *)a) < tolower(*(unsigned char *)b) ? -1 : +1);
}

int main()
{
	assert(stricmp("Abc", "aBC") == 0);
	assert(stricmp("a", "") > 0);
	assert(stricmp("a", "A") == 0);
	assert(stricmp("", "") == 0);
	assert(stricmp("abc", "Ab") > 0);
	assert(stricmp("Ab", "abc") < 0);
	return 0;
}
