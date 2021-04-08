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
