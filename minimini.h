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
char	**ft_split(char const *s, char c);
int		pwd(void);
int		cd(char	**line, t_env **env_list);
int		echo(char **line);
int		env_env(t_env	**env_list);
int		export_export(t_env **env_list, char **line);
int		unset_unset(char **line);
void	make_env_list(t_env **env_list, char **env);
void	ft_lstadd_back(t_env **env_list, t_env *new);
t_env	*ft_lstlast(t_env *env_list);
t_env	*ft_lstnew(char *en_value, char *enviroment);
char	*get_en_value(char *env);
char	*get_enviroment(char *env);
void	add_env_value(char *env, t_env **env_list, char *oldpwd);
#endif
