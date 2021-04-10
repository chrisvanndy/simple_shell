#include "shell.h"
/**
 * countword - counts words from command line string
 * @str: string passed via main
 * @delim: delimiter character
 * Return: int (count)
 */
size_t countword(char *str, char delim)
{
	size_t i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim || str[i + 1] == '\0')
			count++;
	}
	return (count);
}
/**
 * tokenArray - creates an array of tokens
 * @cmd: string passed from main to tokenize
 * @delim: delimiter character
 * @signal: used to identify when function is being called - determines
 * when to append a null byte
 * Return: NULL if failed or 2darray if success
 */
char **tokenArray(char *cmd, char *delim, int signal)
{
	char *token = NULL;
	char **toks;
	int i = 0;
	int len = 0;
	size_t wordcount = 0;

	if (!cmd)
		return (NULL);
	len = _strlen(cmd);
	if (signal == 0)
		cmd[len - 1] = '\0';
	wordcount = countword(cmd, delim[0]);
	toks = malloc(sizeof(char *) * (wordcount + 1));
	if (toks == NULL)
		return (NULL);
	token = strtok(cmd, delim);
	while (token != NULL)
	{
		toks[i] = _strdup(token);
		if (toks[i] == NULL)
		{
			free_toks(toks);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	toks[i] = token;
	return (toks);
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
	free(toks);
}
