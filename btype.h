#ifndef __BTYPE_H__
#define __BTYPE_H__
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct _pword pWord;
struct _pword
{
	char key[27];
	char *word;
};

int getbit(const char);

pWord* genWord(const char *);

void removeWord(pWord *);

#endif