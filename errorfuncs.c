#include "shell.h"
/**
 * errorhandler - handles error message text
 * @av: argv
 * @input: user input
 * @count: for line #
 * Return: void
 */
void errorhandler(char *av, char *input, int count)
{
	char *newstr = NULL, *countstr = NULL;
	int len = _strlen(av);
	int len2 = _strlen(input);
	int len3 = 0;

	countstr = int_to_str(count, countstr);
	if (!countstr)
		return;
	len3 = _strlen(countstr);
	newstr = malloc(sizeof(char) * (len + len2 + len3 + 5));
	if (!newstr)
		return;
	_memset(newstr, '\0', (len + len2 + len3 + 5));
	_strcpy(newstr, av);
	_strcat(newstr, ": ");
	_strcat(newstr, countstr);
	_strcat(newst, ": ");
	_strcat(newstr, input);
	perror(newstr);
	free(newstr);
	free(countstr);
}
/**
 * execError - handles error message text for execve
 * @av: argv
 * @input: user input
 * @count: for line #
 * Return: void
 */
void execError(char *av, char *input, int count)
{
	char *newstr = NULL, *countstr = NULL;
	int len = _strlen(av);
	int len2 = _strlen(input);
	int len3 = 0;

	countstr = int_to_str(count, countstr);
	if (!countstr)
		return;
	len3 = _strlen(countstr);
	newstr = malloc(sizeof(char) * (len + len2 + len3 + 17));
	if (!newstr)
		return;
	_memset(newstr, '\0', (len + len2 + len3 + 17));
	_strcpy(newstr, av);
	_strcat(newstr, ": ");
	_strcat(newstr, countstr);
	_strcat(newstr, ": ");
	_strcat(newstr, input);
	_strcat(newstr, ": not found\n");
	len = _strlen(newstr);
	write(2, newstr, len);
	free(newstr);
	free(countstr);
}
/**
 * int_to_str - converts int to string
 * @n: input int
 * @str: new string
 * Return: converted string
 */
char *int_to_str(int n, char *str)
{
	unsigned int x, i = 0, y = 1000000000;
	unsigned int nn = n;
	int len = 0;

	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		_memset(str, '\0', 2);
	}
	if (nn == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (nn >= 1)
	{
		if (nn >= y)
		{
			x = nn / y;
			len = _strlen(str);
			str = _realloc(str, len, len + 2);
			str[i] = '0' + x;
			i++;
			nn = nn - (x * y);
			y = y / 10;
			while (nn < y)
			{
				str[i] = '0' + 0;
				i++;
				y = y / 10;
			}
		}
		else
			y = y / 10;
	}
	str[i] = '\0';
	return (str);
}
