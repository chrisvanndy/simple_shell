#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: ptr to prev memory
 * @old_size: size (in bytes) previously allocated to ptr
 * @new_size: new size
 * Return: ptr to new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;

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
	nptr = ptr;
	free(ptr);
	nptr = malloc(new_size);
	if (!nptr)
		return (NULL);
	return (nptr);
}
