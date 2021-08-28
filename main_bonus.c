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
	int fd0 = open("../gnlTester/files/41_with_nl", O_RDWR);
	int fd1 = open("../gnlTester/files/42_with_nl", O_RDWR);
	int fd2 = open("../gnlTester/files/43_with_nl", O_RDWR);
	int i = 0;
	/* char guys = 1; */
	/* if (guys) */
	/* 	printf("header"); */
	//nextline = get_next_line(teste);
	//printf("|%s \n|", nextline);
	//while (nextline)
	for (i = 0; i < 5;i++)
	{
		nextline = get_next_line(fd0);
		printf("%s", nextline);
		free(nextline);

		nextline = get_next_line(fd1);
		printf("%s", nextline);
		free(nextline);

		nextline = get_next_line(fd2);
		printf("%s", nextline);
		free(nextline);
	}
	close(fd0);
	close(fd2);
	close(fd1);
}

void free_array(char **s)
{
	for(int i = 0; s[i];i++)
		free(s[i]);
	free(s);
}
