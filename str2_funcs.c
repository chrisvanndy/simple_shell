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
/**
 * funkycat - used to create path strings
 * @dest: destination string
 * @middle: extra char(s) for middle of string
 * @src: source string
 * Return: altered string
 */
char *funkycat(char *dest, char *middle, char *src)
{
	if (dest && src && middle)
	{
		_strcat(dest, middle);
		_strcat(dest, src);
	}
	else
		return (NULL);
	return (dest);
}
/**
 * _strncpy - copies n byes of src to dest
 * @dest: destination string
 * @src: source string
 * @n: number of bytes
 * Return: copy of string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; src[i] && i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
