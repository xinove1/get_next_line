#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void free_array(char **s);
int	main(void)
{
	//char	**nextline = malloc(10 * sizeof(char**));
	char *nextline;
	int teste = open("./teste.txt", O_RDONLY);
	int i = 0;
	/* char guys = 1; */
	/* if (guys) */
	/* 	printf("header"); */
	//nextline = get_next_line(teste);
	//printf("|%s \n|", nextline);
	//while (nextline)
	for (i = 0; i < 10;i++)
	{
		nextline = get_next_line(teste);
		printf("|%s|", nextline);
		free(nextline);
	}
	close(teste);
	//free_array(nextline);
}

void free_array(char **s)
{
	for(int i = 0; s[i];i++)
		free(s[i]);
	free(s);
}
