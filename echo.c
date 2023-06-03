#include "stdio.h"

int	echo(char **line)
{
    int     i;

    i = 1;
	while (line[i])
	{
		printf("%s", line[i]);
		if (line[i + 1])
			printf(" ");
        i++;
	}
	return (0);
}