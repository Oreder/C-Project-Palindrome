#ifndef __EXEC_H__
#define __EXEC_H__
#include "btype.h"
#include "palindrome.h"

int get_list_pWord(const char *, pWord ***, int *);

void exec(pWord **, int);

void remove_list_pWord(pWord **, int);

#endif