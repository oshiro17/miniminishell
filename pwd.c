#include "minimini.h"

#define PATH_SIZE 512

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, PATH_SIZE);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
