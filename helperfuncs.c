#include "shell.h"
/**
 * dirchg - handles "cd" built in via path
 * @cmdtoks: 2d array of tokenized input
 * @av: argv
 * Return: void
 */
void dirchg(char **cmdtoks, char **av)
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
		errorhandler(av[0], cmdtoks[0]);
	}
	if (_strcmp(cmdtoks[1], "~\0") == 0 && cmdtoks[2] == NULL)
	{
		cmdtoks[1] = _realloc(cmdtoks[1], 2, 7);
		cmdtoks[1] = _memset(cmdtoks[1], '\0', 7);
		cmdtoks[1] = _strcpy(cmdtoks[1], path);
	}
	if (chdir(cmdtoks[1]) == 0)
		return;
	errorhandler(av[0], cmdtoks[0]);
}
/**
 * _memset - sets memory
 * @s: string
 * @b: assignment char
 * @n: number of times to copy
 * Return: reset string
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
 * @av: argv
 * Return: void
 */
void errorhandler(char *av, char *input)
{
	char *newstr = NULL;
	int len = _strlen(av);
	int len2 = _strlen(input);

	newstr = malloc(sizeof(char) * (len + len2 + 3));
	_memset(newstr, '\0', (len + len2 + 3));
	_strcpy(newstr, av);
	newstr[len] = ':';
	newstr[len + 1] = ' ';
	_strcat(newstr, input);
	perror(newstr);
	free(newstr);
}
/**
 * _realloc - reallocates a memory block
 * @ptr: ptr to prev memory
 * @old_size: size (in bytes) previously allocated to ptr
 * @new_size: new size
 * Return: ptr to new memory
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
	}
	nptr = malloc(new_size);
	if (!nptr)
		return (NULL);
	for (i = 0; ptr[i] != '\0'; i++)
	{
		nptr[i] = ptr[i];
	}
	nptr[i] = '\0';
	free(ptr);
	return (nptr);
}
