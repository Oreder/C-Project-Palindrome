#include "palindrome.h"

int is_palindrome(const char *src)
{
	int j = strlen(src)-1, i = 0;
	while (i <= j-i)
	{
		if (src[i] != src[j-i])
			break;
		i++;
	}
	if (i <= j - i)
		return 0;
	return 1;
}

int count_palindrome(FILE *fs)
{
	rewind(fs);
	int total = 0;
	char word[__MAX_SIZE__];
	while (fscanf(fs, "%s", word) == 1)
	{
		if (is_palindrome(word))
			total++;
	}
	return total;
}