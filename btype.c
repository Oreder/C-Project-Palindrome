#include "btype.h"
#include <stdio.h>
int getbit(const char src)
{
	int i = 0;
	char c1 = 'a', c2 = 'A';
	while (c1 <= 'z' && c2 <= 'Z')
	{
		if (src == c1 || src == c2)
			break;
		
		c1++;
		c2++;
		i++;
	}
	return i;
}

pWord* genWord(const char *src)
{
	// generate struct
	pWord *tmp = (pWord *)malloc(sizeof(pWord));
	if (!tmp)
		return NULL;
	
	// generate word
	tmp->word = (char *)malloc(sizeof(strlen(src) + 1));
	if (!tmp->word)
		return NULL;
	
	// save word
	strcpy(tmp->word, src);
	
	// initialize key
	for (int i = 0; i < 26; i++)
		tmp->key[i] = '0';

	// configure key
	for (int i = 0, j = strlen(src) - 1; i <= j-i; i++)
	{
		int k = getbit(src[i]);
		if (k != 26)
			tmp->key[k] = '1';
	}
	
	tmp->key[26] = '\0';
	return tmp;
}

void removeWord(pWord *src)
{
	free(src->word);
	free(src);
}