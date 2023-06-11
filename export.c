#include "minimini.h"

int	export_export(t_env **env_list, char **line)
{
	add_env_value(get_enviroment(line[1]), env_list, get_en_value(line[1]));
	return 0;
}