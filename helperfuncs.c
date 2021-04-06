#include "shell.h"
/**
 * countword - counts words from command line string
 * @cmd: string passed via main
 * 
 * Return: int (count)
 */
size_t countword(char *cmd)
{
	size_t i, count = 0;
	
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == ' ' || cmd[i + 1] == '\0')
			count++;
	}

	return (count);	
}
/**
 * tokenArray - creates an array of tokens
 * @cmd: string passed from main to tokenize
 * Return: NULL if failed or 2darray if success
 */
char **tokenArray(char *cmd)
{
	char *token = NULL;
	char **toks;
	int i = 0;
	int len = 0;

	len = _strlen(cmd);
	cmd[len - 1] = '\0';
	toks = malloc(sizeof(char *) * (countword(cmd) + 1));
	if (toks == NULL)
		return (NULL);
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		toks[i] = _strdup(token);
		if (toks[i] == NULL)
		{
			free_toks(toks);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	toks[i] = token;
/*	free(cmd);
*/	return (toks);
}
/** 
 * free_toks - free vertical index of toks
 * @toks: array passed from tokenArray
 *
 * Return: void
 */
void free_toks(char **toks)
{
	int i = 0;

	if (toks == NULL)
		return;
	while (toks[i] != NULL)
	{
		free(toks[i]);
		i++;
	}
/*	free(toks[i]);
*/	free(toks);
}
/** 
 * executecmd - execute path for tokens
 * @tokens: 2d array of args passed from main
 * Return: void
 */
int executecmd(char  **tokens)
{
	int signal = 0;
	pid_t child;
	
	child = fork();
	if (!child)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
/*			errorhandler();
*/			signal = 1;
		}
	}
	else
		wait(NULL);
/*	free_toks(tokens);
*/	return (signal);
}
