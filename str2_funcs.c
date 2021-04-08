#include "shell.h"
/**
 * _bstrcat - concatenates 2 strings, places source BEFORE dest
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char *_bstrcat(char *dest, char *src)
{
	char *temp = NULL;

	if (dest && src)
	{
		temp = _strdup(dest);
		if (!temp)
			return (NULL);
		if (src)
		{
			_strcpy(dest, src);
		}
		if (temp)
		{
			_strcat(dest, temp);
		}
		free(temp);
	}
	return (dest);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int ii = 0;

	if (dest && src)
	{
		while (dest[i])
			i++;
		while (src[ii])
		{
			dest[i] = src[ii];
			i++;
			ii++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
