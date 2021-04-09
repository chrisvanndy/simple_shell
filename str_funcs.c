#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference bewteen strings, or 0 if strings are the same
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (1);
	for (; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	}
	return (0);
}
/**
 * _strncmp - compares n bytes of 2 strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 0 if match, or difference between strings
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (!s1 || !s2 || n < 0)
		return (1);
	for (; (s1[i] || s2[i]) && n > 0; i++, n--)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strlen - finds length of a string
 * @s: the string
 * Return: count of characters
 */
int _strlen(char *s)
{
	int i = 0;

	while (s && s[i])
		i++;
	return (i);
}
/**
 * _strdup - allocates memory for a copied string
 * @str: the string to copy
 * Return: NULL if string == NULL or ptr to copied string
 */
char *_strdup(char *str)
{
	char *dup;
	int i = 0;

	if (!str)
		return (NULL);
	dup = (char *)malloc(_strlen(str) + 1);
	if (!dup)
		return (NULL);
	for (; str[i]; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
/**
 * _strcpy - copies a string
 * @dest: destination of copy
 * @src: the source to copy from
 * Return: ptr to copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!src)
		return (NULL);
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
