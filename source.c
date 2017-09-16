#include "exec.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error 1: Command has not enough parameters!\n");
		return -1;
	}
	
	pWord **list = NULL;
	int count;
	
	get_list_pWord(argv[1], &list, &count);
	if (count)
	{
		exec(list, count);
		remove_list_pWord(list, count);
	}
	
	return 0;
}