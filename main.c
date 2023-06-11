#include "minimini.h"
// }	t_env;

char	*get_enviroment(char *env)
{
	int		i;
	char	*rec;

	i = 0;
	while (env[i]&&env[i] != '=')
		i++;
	rec = (char *)malloc(i + 1);
	i = 0;
	while (env[i]&&env[i] != '=')
	{
		rec[i] = env[i];
		i++;
	}
	rec[i] = '\0';
	return (rec);
}

char	*get_en_value(char	*env)
{
	int		i;
	int		k;
	int		mark;
	char	*rec;

	mark = 0;
	i = 0;
	k = 0;
	while (env[i] && env[i] != '=')
		i++;
	while (env[i + k])
	{
		if (env[i + k] == '"')
			mark++;
		k++;
	}
	rec = (char *)malloc(k + 1 - mark);
	k = 0;
	i++;
	if (mark == 2)
		i++;
	while (env[i] && env[i]!= '"')
	{
		rec[k] = env[i];
		i++;
		k++;
	}
	rec[k] = '\0';
	return (rec);
}

t_env	*ft_lstnew(char *en_value, char *enviroment)
{
	t_env	*new_list;

	new_list = (t_env *)malloc(sizeof(t_env));
	new_list->enviroment = enviroment;
	new_list->en_value = en_value;
	new_list->next = NULL;
	return (new_list);
}
t_env	*ft_lstlast(t_env *env_list)
{
	while (env_list && env_list->next)
		env_list = env_list->next;
	return (env_list);
}

void	ft_lstadd_back(t_env **env_list, t_env *new)
{
	t_env	*last;

	if (!env_list || !new)
		return ;
	if (*env_list)
	{
		last = ft_lstlast(*env_list);
		last->next = new;
	}
	else
		*env_list = new;
	return ;
}

void	make_env_list(t_env	**env_list,	char	**env)
{
	t_env	*new_list;
	int		i;

	i = 0;
	while (env[i])
	{
		new_list = ft_lstnew(get_en_value(env[i]),get_enviroment(env[i]));
		i++;
		ft_lstadd_back(env_list, new_list);
	}
}


int	main(int argc, char **argv, char **env)
{
	char	**line;
	t_env	*env_list;

	env_list = NULL;
	(void)argc;
	(void)argv;
	line = NULL;
	make_env_list(&env_list, env);
	while (1)
	{
		line = ft_split(readline("minishell>>"), ' ');
		if (*line == NULL)
			;
		else if ( line == NULL || !strcmp(line[0], "exit"))
		{
			free(line);
			break ;
		}
		else if (strlen(line[0]) == 0)
			;
		else
		{
			if (!line[1])
			{
				if (!strcmp(line[0], "env"))
					env_env(&env_list);
				if (!strcmp(line[0], "pwd"))
					pwd(line);
			}
			if (!strcmp(line[0], "echo"))
				echo(line);
			if (!line[2])
			{
				if (!strcmp(line[0],"cd"))
					cd(line, &env_list);
				if (!strcmp(line[0], "unset"))
					unset_unset(&env_list, line);
				if (!strcmp(line[0], "export"))
					export_export(&env_list, line);
			}
			free (line);
		}
	}
	printf("exit");
	return (0);
}