#include "minimini.h"

int	echo(char **line)
{
    int     i;
    bool    new_line;

    new_line = false;
    i = 1;
    if (!strcmp(line[i],"-n"))
    {
        i++;
        new_line = true;
    }
	while (line[i])
	{
		printf("%s", line[i]);
		if (line[i + 1])
			printf(" ");
        i++;
	}
    if (new_line)
        printf("\n");
	return (0);
}