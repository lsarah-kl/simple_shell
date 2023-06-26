#include "main.h"

/**
 * _memcpy1 - function that copies a block of memory from the source
 *           pointer to the destination pointer.
 * @new_pointer: The destination pointer.
 * @pointer: The source pointer.
 * @s: size of the new pointer.
 *
 * Return: None.
 */
void _memcpy1(void *new_pointer, const void *pointer, unsigned int s)
{
	char *char_ptr = (char *)pointer;
	char *char_newptr = (char *)new_pointer;
	unsigned int i;

	for (i = 0; i < s; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc1 - function that reallocates a memory block with a new size.
 * @pointer: Pointer to the mem previously allocated.
 * @old_s: Size, in bytes of the allocated space for ptr.
 * @new_s: New siz in bytes, of the reallocated memory block.
 *
 * Return: Pointer to the reallocated memory block (ptr).
 */
void *_realloc1(void *pointer, unsigned int old_s, unsigned int new_s)
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
		_memcpy1(newptr, pointer, new_s);
	else
		_memcpy1(newptr, pointer, old_s);

	free(pointer);
	return (newptr);
}

/**
 * _reallocdp1 - Reallocates memory block of  double pointer.
 * @pointer: Double pointer to the mem previously allocated.
 * @old_s: Size, in bytes of the allocated space for pointer.
 * @new_s: New size, in bytes of the reallocated memory block.
 *
 * Return: Pointer to the reallocated memory block.
 */
char **_reallocdp1(char **pointer, unsigned int old_s, unsigned int new_s)
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
