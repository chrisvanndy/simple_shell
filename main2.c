#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
/**
 * main - accepts and executes commands
 * @argc: # of command line args
 * @argv: list of command line args stored as strings
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	char *cmd;

	(void)argc;
	(void)argv;
	while (1)
	{
		print_prompt1();

		cmd = read_cmd();

		if (!cmd)	/* do we need this? */
			exit(EXIT_SUCCESS);

		if (cmd[0] == '\0' || _strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		if (_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}
		cmd[_strlen(cmd)] = '\n';
		write(1, cmd, _strlen(cmd));
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}
/**
 * read_cmd - reads commands
 * Return: ptr to input string
 */
char *read_cmd(void)
{
	char *ptr = NULL;
	size_t bufsize = 1024, ptrlen = 0, getlineval = 0;

	while (getlineval != -1)
	{
		getlineval = getline(&ptr, &bufsize, stdin);
		ptrlen = _strlen(ptr);
		if (ptr[ptrlen - 1] == '\n')
		{
			if (ptrlen == 1 || ptr[ptrlen - 2] != '\\')
				return ptr;
			ptr[ptrlen - 2] = '\0';
			print_prompt2();
		}
	}
	return (ptr);
}
