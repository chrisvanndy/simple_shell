#include "shell.h"
/** 
 * executecmd - execute path for tokens
 * @tokens: 2d array of args passed from main
 * Return: void
 */
int executecmd(char **tokens, char *cmd)
{
	int signal = 0;
	int len = 0;
	pid_t child;

	if (_strncmp(tokens[0], "/bin/", 5) != 0)
	{
		len = _strlen(tokens[0]);
		tokens[0] = _realloc(tokens[0], len, len + 6);
		if (!tokens[0])
			return (1);
		tokens[0] = _bstrcat(tokens[0], "/bin/");
	}
/*   while (my_aliases != NULL)
	{
		if (_strcmp(tokens[0], my_aliases->alias_name) == 0)
		{
			len = _strlen(tokens[0]
		}
	}
*/	child = fork();
	if (!child)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
/*			errorhandler();
*/			free(cmd);
			free_toks(tokens);
			perror("./hsh");
			exit(-1);
		}
	}
	else
		wait(NULL);
	return (signal);
}
/**
 * dirchg - handles "cd" built in via path
 * @cmdtoks - 2d array of tokenized input
 * Return: void
 */
void dirchg(char **cmdtoks)
{
	char *path = "/home/";
	int len;

	if (cmdtoks[1] == NULL) 
	{
		len = _strlen(cmdtoks[1]);
		cmdtoks[0] = _realloc(cmdtoks[0], len, 7);
		cmdtoks[0] = _strcpy(cmdtoks[0], path);
		if (chdir(cmdtoks[0]) == 0)
			return;
		else
		{
			errorhandler();
			return;
		}
	}
	if (_strcmp(cmdtoks[1], "~\0") == 0 && cmdtoks[2] == NULL)
	{
		cmdtoks[1] = _realloc(cmdtoks[1], 2, 7);
		cmdtoks[1] = _memset(cmdtoks[1], '\0', 7);
		cmdtoks[1] = _strcpy(cmdtoks[1], path);
	}
	if (chdir(cmdtoks[1]) == 0)
		return;
	else 
		errorhandler();
}
/**
 * _memset - sets memory
 * @s: string
 * @b: assignment char
 * @n: number of times to copy
 * Reutnr: reset string
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
/**
 * errorhandler - handles error message text
 * Return: void
 */
void errorhandler(void)
{
	perror("./hsh");
}
