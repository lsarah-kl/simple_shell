#include "main.h"

/**
 * main - Entry point.
 * @argc: Arg count.
 * @argv: Arg vector.
 *
 * Return: 0 if success.
 */
int main(int argc, char **argv)
{
	shll_comm datash;
	(void)argc;

	signal(SIGINT, get_sigint);
	set_datashell(&datash, argv);
	looping_shll(&datash);
	empty_data(&datash);
	if (datash.stat < 0)
		return (255);
	return (datash.stat);
}
