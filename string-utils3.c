#include "main.h"

/**
 * _strspn1 - function that calculates the len of initial segment of a
 *           string that consists of only accepted bytes.
 * @str: Pointer to the string to search.
 * @acc: Pointer to accepted bytes.
 *
 * Return: The len of the prefix substring that consists
 *         of only accepted bytes.
 */
int _strspn1(char *str, char *acc)
{
	int i, j, boolean;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		boolean = 1;
		for (j = 0; *(acc + j) != '\0'; j++)
		{
			if (*(str + i) == *(acc + j))
			{
				boolean = 0;
				break;
			}
		}
		if (boolean == 1)
			break;
	}

	return (i);
}

/**
 * _strcat1 - Concatenates two strings.
 * @dest: Pointer to  destination string
 * @src: Pointer to the source string
 *
 * Return: Pointer to the destination string after concatenation.
 */
char *_strcat1(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp1 - Compares two strings.
 * @str1: Pointer to the 1st string to compare.
 * @str2: Pointer to the 2nd string to compare.
 *
 * Return: 0 if the strings are equal, a positive value if str1 is greater,
 *         a negative value if str2 is greater.
 */
int _strcmp1(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;

	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);

	return (0);
}

/**
 * _strchr1 - Locates a character in a string.
 * @str: Pointer to the string to search.
 * @c: Character to locate.
 *
 * Return: Pointer to the first occurrence of the character 'c' in 'str',
 *         or NULL if the character is not found.
 */
char *_strchr1(char *str, char c)
{
	unsigned int i = 0;

	for (; *(str + i) != '\0'; i++)
		if (*(str + i) == c)
			return (str + i);
	if (*(str + i) == c)
		return (str + i);
	return ('\0');
}

/**
 * _strcpy1 - function that copies the string pointed to by src to dest.
 * @dest: Pointer to the destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy1(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];

	dest[a] = '\0';

	return (dest);
}
