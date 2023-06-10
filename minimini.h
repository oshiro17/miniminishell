#ifndef	MINIMINI_H
#define MINIMINI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_env
{
	char	*enviroment;
	char	*en_value;
	struct s_env	*next;
}	t_env;

int		main(int argc, char **argv, char**env);
char	**ft_split(char *c);
int		pwd(void);
int		cd(char	**line, t_env **env_list);
int		echo(char **line);

#endif
