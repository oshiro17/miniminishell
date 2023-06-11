#include "minimini.h"

int env_env(t_env **env_list)
{
	t_env *list;

	list = *env_list;
	while (list)
	{
		printf("%s",list->enviroment);
		printf("=");
		printf("%s\n",list->en_value);
		list = list->next;
	}
	return(0);
}