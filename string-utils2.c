#include "main.h"

/**
 * conv_itoa1 - function that converts an integer to a string.
 * @number: The int number to convert.
 *
 * Return: string representation of the integer.
 */
char *conv_itoa1(int number)
{
	unsigned int n1;
	int len = get_length(number);
	char *buff;

	buff = malloc(sizeof(char) * (len + 1));
	if (buff == 0)
		return (NULL);

	*(buff + len) = '\0';

	if (number < 0)
	{
		n1 = number * -1;
		buff[0] = '-';
	}
	else
		n1 = number;

	len--;
	do {
		*(buff + len) = (n1 % 10) + '0';
		n1 = n1 / 10;
		len--;
	} while (n1 > 0);
	return (buff);
}

/**
 * get_length1 - Gets the length of number.
 * @number: The number to calculate the length of
 *
 * Return: The length of the number.
 */
int get_length1(int number)
{
	unsigned int n1;
	int lenght = 1;

	if (number < 0)
	{
		lenght++;
		n1 = number * -1;
	}
	else
		n1 = number;
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}

/**
 * _atoi1 - Converts a string to an integer.
 * @str: Input string.
 *
 * Return:  converted integer.
 */
int _atoi1(char *str)
{
	unsigned int counter = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(str + counter) != '\0')
	{
		if (size > 0 && (*(str + counter) < '0' || *(str + counter) > '9'))
			break;

		if (*(str + counter) == '-')
			pn *= -1;

		if ((*(str + counter) >= '0') && (*(str + counter) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		counter++;
	}

	for (i = counter - size; i < counter; i++)
	{
		oi = oi + ((*(str + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
