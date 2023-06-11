#include "minimini.h"
#include "minimini.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*rec;
	size_t		i;
	size_t		k;

	if (!s1 | !s2)
		return (NULL);
	rec = malloc(strlen(s1) + strlen(s2));
	if (!rec)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		rec[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i])
	{
		rec[k] = s2[i];
		i++;
		k++;
	}
	return (rec);
}

char	*catch_env_value(char *env, t_env	**env_list)
{
	t_env	*list;

	list = *env_list;
	while(list)
	{
		// printf("%s", list->en_value); 
		if (!strncmp(env, list->enviroment, strlen(env) + 1))
			return (list->en_value);
		list = list->next;
	}
	// printf("%s",env);
	return(NULL);
}

void	add_env_value(char *env, t_env **env_list, char *oldpwd)
{
	t_env	*list;

	list = *env_list;
	if (env[0] && oldpwd[0])
	{
		while (list)
		{
			if (!strncmp(env,list->enviroment,strlen(env) + 1))
			{
				list->en_value = oldpwd;
				return ;
			}
			list = list->next;
		}
		list = ft_lstnew(oldpwd, env);
		ft_lstadd_back(env_list, list);
	}
	return ;
}

int	cd(char	**line, t_env **env_list)
{
	char	*dir;
	char	*oldpwd;

	if (!line)
		return (0);
	else if (!line[1])
	{
		oldpwd = getcwd(NULL, 0);
		dir = catch_env_value("HOME", env_list);
		chdir(dir);
		add_env_value("PWD", env_list, dir);
		add_env_value("OLDPWD", env_list, oldpwd);
	}
	chdir(line[1]);
	return (0);
}
