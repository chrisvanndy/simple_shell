#include "shell.h"
/**
 * main - accepts and executes commands
 * @ac: # of command line args
 * @av: list of command line args stored as strings
 * Return: 0 if success
 */
int main(int ac, char **av)
{
	char *cmd = NULL, *path = NULL;
	int mode, comp = 0, count = 0, n = 0;
	char **cmdtoks;

	(void)ac;
	signal(SIGINT, SIG_IGN);
	mode = isatty(STDIN_FILENO);
	while (1)
	{
		count++;
		if (mode)
			print_prompt1();
		cmd = read_cmd();
		if (!cmd)
		{
			if (mode)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		cmdtoks = tokenArray(cmd, " ", 0);
		if (cmdtoks == NULL)
		{
			free(cmd);
			continue;
		}
		comp = compareStr(av, cmd, cmdtoks, count);
		if (comp == 0)
			continue;
		if (comp == -1)
			break;
		path = find_path(cmdtoks);
		if (!path)
		{
			free(cmd), free_toks(cmdtoks), errorhandler(av[0], cmdtoks[0], count);
			continue;
		}
		n = executecmd(av, cmdtoks, path, cmd, count);
		free_toks(cmdtoks), free(cmd), cmd = NULL, cmdtoks = NULL;
	}
	free_toks(cmdtoks), free(cmd), exit(n);
}
/**
 * read_cmd - reads commands
 * Return: ptr to input string
 */
char *read_cmd(void)
{
	char *buf = NULL, *ptr = NULL, *ptr2;
	ssize_t ptrlen = 0, buflen = 0;
	size_t bufsize = 1024;

	while (getline(&buf, &bufsize, stdin) != -1)
	{
		buflen = _strlen(buf);
		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			ptr2 = _realloc(ptr, ptrlen, ptrlen + buflen + 1);
			if (ptr2)
				ptr = ptr2;
			else
				free(ptr), ptr = NULL;
		}
		if (!ptr)
		{
			perror("error: failed to alloc buffer: "), free(buf);
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
/**
 * compareStr - compares string to unique cases
 * @av: argv
 * @cmd: input string
 * @toks: 2d array of tokens
 * @count: keeps count for error msgs
 * Return: 0 if continue, -1 if break, 1 if no match
 */
int compareStr(char **av, char *cmd, char **toks, int count)
{
	if (toks[0] == '\0' || _strcmp(toks[0], "\n\0") == 0)
	{
		free(cmd);
		free_toks(toks);
		return (0);
	}
	if (_strcmp(toks[0], "cd\0") == 0)
	{
		dirchg(toks, av, count);
		free(cmd);
		free_toks(toks);
		return (0);
	}
	if (_strcmp(toks[0], "exit") == 0)
		return (-1);

	return (1);
}
