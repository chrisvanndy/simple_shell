#include "shell.h"
/**
 * find_path - finds the path
 * @toks: token array
 * Return: Full path if command exists, or NULL if not
 */
char *find_path(char **toks)
{
	int i = 0, signal = 0;
	size_t len = 0, len2 = _strlen(toks[0]);
	char *newstr = NULL;
	char **path = NULL;
	struct stat statvar;

	/* Loop through environ to find PATH */
	for (i = 0; environ[i]; i++)
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			break;
	/* Create 2d array for paths */
	newstr = _strdup(environ[i]);
/*	len = countword(newstr + 5, ':');
*/	path = tokenArray(newstr + 5, ":", 1);
	free(newstr);
	newstr = NULL;
	/* Check if full path has been specified by user */
	for (i = 0; path[i]; i++)
	{
		newstr = check_path(toks[0]);
		if (_strcmp(path[i], newstr) == 0)
		{
			free(newstr);
			free_toks(path);
			return (toks[0]);
		}
		else
		{
			if (newstr)
				free(newstr);
			newstr = NULL;
		}
	}
	/* Append command string to each path */
	for (i = 0; path[i]; i++)
	{
		len = _strlen(path[i]);
		path[i] = _realloc(path[i], len, len + len2 + 2);
		path[i] = funkycat(path[i], "/", toks[0]);
	}
	/* Loop through path array and use stat to check if command exists */
	for (i = 0; path[i]; i++)
	{
		if (stat(path[i], &statvar) == 0)
		{
			signal = 1;
			break;
		}
	}
	/* If valid command is found, return the path to the command */
	if (signal == 1)
	{
		len = _strlen(path[i]);
		toks[0] = _realloc(toks[0], len2, len + 1);
		_strcpy(toks[0], path[i]);
		free_toks(path);
		return (toks[0]);
	}
	/* Otherwise, return user input */
	else
	{
		free(newstr);
		free_toks(path);
		return (toks[0]);
	}
	return (toks[0]);
}
/**
 * check_path - checks if user has given a full path
 * @str: input string
 * Return: path, if it exists, or NULL otherwise
 */
char *check_path(char *str)
{
	int i = 0, count = 0, count2 = 0, count3 = 0;
	char *newstr = NULL;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			count++;
	}
	if (count == 0)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			count2++;
		if (count == count2)
			break;
		count3++;
	}
	newstr = malloc(sizeof(char) * count3 + 1);
	if (!newstr)
		return (NULL);
	_strncpy(newstr, str, count3);
	return (newstr);
}
