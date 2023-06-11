#include "minimini.h"

#define PATH_SIZE 512

int	pwd(char **line)
{
	char	*pwd;

	if (!line[1])
	{
		pwd = getcwd(NULL, PATH_SIZE);
		printf("%s\n", pwd);
		free(pwd);
	}
	return (0);
}
