#include "shell.h"
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
