#include "shell.h"
/**
 * dirchg - handles "cd" built in via path
 * @cmdtoks: 2d array of tokenized input
 * @av: argv
 * @count: keeps count of line #
 * Return: void
 */
void dirchg(char **cmdtoks, char **av, int count)
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
		errorhandler(av[0], cmdtoks[0], count);
	}
	if (_strcmp(cmdtoks[1], "~\0") == 0 && cmdtoks[2] == NULL)
	{
		cmdtoks[1] = _realloc(cmdtoks[1], 2, 7);
		cmdtoks[1] = _memset(cmdtoks[1], '\0', 7);
		cmdtoks[1] = _strcpy(cmdtoks[1], path);
	}
	if (chdir(cmdtoks[1]) == 0)
		return;
	errorhandler(av[0], cmdtoks[0], count);
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
/**
 * _memcpy - copies n bytes from *src to *dest
 * @dest: destination
 * @src: source
 * @n: number of times to copy
 * Return: destination string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
/**
 * print_env - mimics the built-in env
 * Retrun: void
 */
void print_env(void)
{
	int i, len = 0;
	
	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len + 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}
