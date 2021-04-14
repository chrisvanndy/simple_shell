#include "shell.h"
/**
 * executecmd - execute command input by user
 * @av: argv
 * @toks: 2d array of args passed from main
 * @path: path to executable
 * @cmd: input str - freed upon error
 * @count: keeps track of line #
 * Return: void
 */
int executecmd(char **av, char **toks, char *path, char *cmd, int count)
{
	pid_t child;
	int status, exit_status = 0;
	char *temp = NULL;

	temp = _strdup(path);
	free(toks[0]);
	toks[0] = temp;
	child = fork();
	if (child == -1)
		errorhandler(av[0], toks[0], count);
	if (child == 0)
	{
		if (execve(toks[0], toks, environ) == -1)
		{
			execError(av[0], toks[0], count);
			free(cmd);
			free_toks(toks);
			exit(127);
		}
	}
	else
		waitpid(child, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);

	return (exit_status);
}
