#include "exec.h"

int get_list_pWord(const char *fileName, pWord ***list, int *count)
{
	FILE *fs = fopen(fileName, "r");
	if (!fs)
		return 0;
	
	*count = count_palindrome(fs);
	if (*count == 0)
		return 0;

	*list = (pWord **)malloc((*count) * sizeof(pWord *));
	char word[__MAX_SIZE__];
	int i = 0;
	
	rewind(fs);
	while (fscanf(fs, "%s", word) == 1)
	{
		if (is_palindrome(word))
		{
			pWord *tmp = genWord(word);
			if (tmp)
			{	
				(*list)[i] = tmp;
				i++;
			}
		}
	}
	
	fclose(fs);
	return 1;
}

void exec(pWord **list, int total)
{
	// initialize key-map
	int *lamp = (int *)malloc(total * sizeof(int));
	
	int j = 0, type = 1;
	while (j <= total)
		lamp[j++] = 0;
	
	j = 0;
	while (j <= total)
	{
		if (lamp[j] != 1)
		{
			printf("++ Type %d: [%s]", type, list[j]->word);
		
			int count = 1;
			for (int i = j+1; i < total; i++)
			{
				if (lamp[i] == 0 && strcmp(list[j]->key, list[i]->key) == 0)
				{
					count++;
					lamp[i] = 1;
					printf(", [%s]", list[i]->word);
				}
			}
			
			printf("\n-> Found: %d\n\n", count);
			type++;
		}
		j++;
	}
	
	free(lamp);
}

void remove_list_pWord(pWord **list, int total)
{
	for (int j = 0; j < total; j++)
		removeWord(list[j]);
	free(list);
}