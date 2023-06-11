#include "minimini.h"

void	free_list(t_env *env)
{
	free(env->en_value);
	free(env->enviroment);
	free(env->next);
	free(env);
}

int	unset_unset(t_env **env_list, char **line)
{
	t_env	*list;
	t_env	*old_list;

	if (line[1])
	{
		list = *env_list;
		old_list = *env_list;
		while (list)
		{
			if (!strncmp(line[1], list->enviroment, strlen(list->enviroment)))
			{
				if (!list->next)
					old_list->next = NULL;
				else
					old_list->next = list->next;
				free_list(list);
				return (0);
			}
			old_list = list;
			list = list->next;
		}
	}
	return (0);
}