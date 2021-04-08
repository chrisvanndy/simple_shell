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
int main(void)
{
	char *cmd = NULL;
	int mode, signal = 0;
	char **cmdtoks;

	mode = isatty(STDIN_FILENO);
	while (1)
	{
		if (mode)
			print_prompt1();
		cmd = read_cmd();
		if (!cmd)
			exit(EXIT_SUCCESS);
		if (cmd[0] == '\0' || _strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		cmdtoks = tokenArray(cmd);
/*		if (cmdtoks == NULL) do stuff;
*/ 		if (_strcmp(cmdtoks[0], "exit\0") == 0 && cmdtoks[1] == NULL)
			break;
		executecmd(cmdtoks, cmd);
		if (signal == 1)
			write(1, cmd, _strlen(cmd));
		if (!mode)
			break;
		free_toks(cmdtoks);
		free(cmd);
	}
	free_toks(cmdtoks);
	free(cmd);
	exit(EXIT_SUCCESS);
}
/**
 * read_cmd - reads commands
 * Return: ptr to input string
 */
char *read_cmd(void)
{
	char *buf = NULL, *ptr = NULL, *ptr2;
	ssize_t ptrlen = 0, getlineval = 0, buflen = 0;
	size_t bufsize = 1024;

	while (getlineval != -1)
	{
		getlineval = getline(&buf, &bufsize, stdin);
		buflen = _strlen(buf);
		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			ptr2 = _realloc(ptr, ptrlen, ptrlen + buflen + 1);
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
			perror("error: failed to alloc buffer: ");
			free(buf);
			return (NULL);
		}
		_strcpy(ptr + ptrlen, buf);
		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
			{	
				free(buf);
				return (ptr);
			}
			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			print_prompt2();
		}
		ptrlen += buflen;
	}
	free(buf);
	return (ptr);
}
