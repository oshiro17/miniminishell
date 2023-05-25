#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv, char**env)
{
	char	*line;

	(void)argc;
	(void)argv;
	line = NULL;
	while (1)
	{
		line = readline("minishell>>");
		if ( line == NULL|| !strcmp(line, "exit"))
		{
			free(line);
			break ;
		}
		else if (strlen(line) == 0)
			;
		else
		{
			// if (!strcmp(line,"cd"))
			// 	cd();
			printf("%s\n",line);
			add_history(line);
			free(line);
		}
	}
	printf("%s\n",env[0]);
	printf("おわり\n");
	return (0);
}
