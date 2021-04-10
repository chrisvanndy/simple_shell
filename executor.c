#include "shell.h"
/**
 * executecmd - execute command input by user
 * @av: argv
 * @toks: 2d array of args passed from main
 * @path: path to executable
 * @cmd: input str - freed upon error
 * Return: void
 */
void executecmd(char **av, char **toks, char *path, char *cmd)
{
	pid_t child;
	char *temp = NULL;

	temp = _strdup(path);
	free(toks[0]);
	toks[0] = temp;
	child = fork();
	if (!child)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(toks[0], toks, environ) == -1)
		{
/*			errno = 
*/			errorhandler(av[0], toks[0]);
			free(cmd);
			free_toks(toks);
			exit(-1);
		}
	}
	else
		wait(NULL);
}
