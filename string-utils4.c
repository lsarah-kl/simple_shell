#include "main.h"

/**
 * _strlen1 - function that returns the length of a string.
 * @str: The input string.
 *
 * Return: the string length
 */
int _strlen1(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * _isdigit1 - tells if a string consists only of numeric digits.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string consists only of numeric digits, 0 otherwise.
 */
int _isdigit1(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (1);
}

/**
 * _strdup1 - Duplicates a string in heap memory.
 * @str: Type char pointer representing the string to be duplicated
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup1(const char *str)
{
	char *new;
	size_t length;

	length = _strlen(str);
	new = malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, str, length + 1);

	return (new);
}

/**
 * compare_chars1 - Compares characters of strings.
 * @str: Input string to compare.
 * @delimiter: Delimiter string for comparison.
 *
 * Return: 1 if the chars are equal, 0 otherwise.
 */
int compare_chars1(char str[], const char *delimiter)
{
	unsigned int i, l, m;

	for (i = 0, m = 0; str[i]; i++)
	{
		for (l = 0; delimiter[l]; l++)
		{
			if (str[i] == delimiter[l])
			{
				m++;
				break;
			}
		}
	}
	if (i == m)
		return (1);
	return (0);
}

/**
 * _strtok1 - Splits a string with a specified delimiter.
 * @str: Input string to be split.
 * @delimiter: Delimiter string.
 *
 * Return: Pointer to the next token in the string,
 *         or NULL if no more tokens are found.
 */
char *_strtok1(char str[], const char *delimiter)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (compare_chars(str, delimiter))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delimiter[i]; i++)
		{
			if (*splitted == delimiter[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}
