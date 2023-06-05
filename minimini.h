#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>
int	main(int argc, char **argv, char**env);
char	**ft_split(char *c);
int	pwd(void);
int	cd(char	**line);
int	echo(char **line);