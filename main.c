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
	char buf[1024], *ptr = NULL;
	char ptrlen = 0;
	int readval;

	while ((readval = read(0, buf, 1024)) > 0)
	{
		int buflen = _strlen(buf);

		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			char *ptr2 = _realloc(ptr, buflen + 1, ptrlen + buflen + 1);
			
			if (ptr2)
				ptr = ptr2;
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{
			write(2, strerror(errno), _strlen(strerror(errno)));
			return (NULL);
		}
		_strcpy (ptr + ptrlen, buf);
		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
				return (ptr);
			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			print_prompt2();	
		}
		ptrlen += buflen;
	}
	return (ptr);
}
