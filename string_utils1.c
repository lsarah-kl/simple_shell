#include "main.h"

/**
 * _memcpy - function that copies a block of mem from  source
 *           pointer to the destination pointer.
 * @new_pointer: The destination pointer.
 * @pointer: The source pointer.
 * @s: The size of the new pointer.
 *
 * Return: Nithing
 */
void _memcpy(void *new_pointer, const void *pointer, unsigned int s)
{
	char *char_ptr = (char *)pointer;
	char *char_newptr = (char *)new_pointer;
	unsigned int i;

	for (i = 0; i < s; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Reallocates a memory block with a new size.
 * @pointer: Pointer to the memory previously allocated.
 * @old_s: Size, in bytes of the allocated space for ptr.
 * @new_s: New size of  reallocated memory block.
 *
 * Return: Pointer to the reallocated memory block (ptr).
 */
void *_realloc(void *pointer, unsigned int old_s, unsigned int new_s)
{
	void *newptr;

	if (pointer == NULL)
		return (malloc(new_s));

	if (new_s == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (new_s == old_s)
		return (pointer);

	newptr = malloc(new_s);
	if (newptr == NULL)
		return (NULL);

	if (new_s < old_s)
		_memcpy(newptr, pointer, new_s);
	else
		_memcpy(newptr, pointer, old_s);

	free(pointer);
	return (newptr);
}

/**
 * _reallocdp - Reallocates a memory block of a double pointer.
 * @pointer: Double pointer to the mem previously allocated.
 * @old_s: Size, in bytes of allocated space for pointer.
 * @new_s: New size, in bytes of the reallocated memory block.
 *
 * Return: Pointer to reallocated memory block 
 */
char **_reallocdp(char **pointer, unsigned int old_s, unsigned int new_s)
{
	char **newptr;
	unsigned int i;

	if (pointer == NULL)
		return (malloc(sizeof(char *) * new_s));

	if (new_s == old_s)
		return (pointer);

	newptr = malloc(sizeof(char *) * new_s);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_s; i++)
		newptr[i] = pointer[i];

	free(pointer);

	return (newptr);
}
