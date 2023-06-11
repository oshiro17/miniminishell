#include "minimini.h"

void	free_list(t_env *env)
{
	free(env->en_value);
	free(env->enviroment);
	free(env);
}

int	unset_unset(t_env **env_list, char **line)
{
	t_env	*cur_node;
	t_env	*prev_node;

	if (line[1])
	{
		cur_node = *env_list;
		prev_node = NULL;
		while (cur_node)
		{
			if (!strncmp(line[1], cur_node->enviroment, strlen(cur_node->enviroment)))
			{
				if (!prev_node)
					*env_list = cur_node->next;
				else
					prev_node->next = cur_node->next;
				free_list(cur_node);
				return (0);
			}
			prev_node = cur_node;
			cur_node = cur_node->next;
		}
	}
	return (0);
}