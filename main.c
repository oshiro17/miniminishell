#include "minimini.h"

typedef struct s_env t_env;

typedef struct s_env
{
	char	*enviroment;
	char	*en_value;
	t_env	*next;
}	t_env;

char	*get_enviroment(char *env)
{
	int		i;
	char	*rec;

	i = 0;
	while (env[i] != '=')
		i++;
	rec = (char *)malloc(i + 1);
	i = 0;
	while (env[i] != '-')
	{
		rec[i] = env[i];
		i++;
	}
	rec[i] = '\0';
	return (rec);
}

char	*get_en_value(char *env)
{
	int		i;
	int		k;
	char	*rec;

	i = 0;
	k = 0;
	while (env[i] != '=')
		i++;
	i++;
	while (env[i + k])
		k++;
	rec = (char *)malloc(k + 1);
	k = 0;
	while (env[i])
	{
		rec[k] = env[i];
		i++;
		k++;
	}
	rec[k] = '\0';
	return (rec);
}

t_env	*ft_lstnew(char *env)
{
	char	*enviroment;
	char	*en_value;
	t_env	*new_list;

	enviroment = get_enviroment(env);
	en_value = get_en_value(env);
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
		// printf("LINE == %d, FILE == %s\n", __LINE__, __FILE__);
		last = ft_lstlast(*env_list);
		// printf("LINE == %d, FILE == %s\n", __LINE__, __FILE__);
		last->next = new;
	}
	else
	{
		*env_list = new;
	}
	return ;
}

void	make_env_list(t_env **env_list, char **env)
{
	t_env	*new_list;
	int		i;

	i = 0;
	while (env[i] && i<10)
	{
		new_list = ft_lstnew(env[i]);
		printf("b\n");
		i++;
		ft_lstadd_back(env_list, new_list);
	}
	printf("c\n");
}

int	main(int argc, char **argv, char	**env)
{
	// char	*line_tmp;
	char	**line;
	t_env	*env_list;

	env_list = NULL;
	(void)argc;
	(void)argv;
	line = NULL;
	make_env_list(&env_list, env);
	while (env_list->next)
	{
		printf("%s\n",env_list->en_value);
		printf("%s\n",env_list->enviroment);
		env_list = env_list->next;
	}
	while (1)
	{
		line = ft_split(readline("minishell>>"));
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
			if (!strcmp(line[0], "pwd"))
				pwd();
			if (!strcmp(line[0], "echo"))
				echo(line);
			if (!strcmp(line[0],"cd"))
				cd(line);

			if (!strcmp(line[0], ""))
			// printf("%s\n", line[0]);
			free (line);
		}
	}
	printf("exit");
	return (0);
}
// #include<stdio.h>
// #include<string.h>
// #include<unistd.h>

// #define PATHNAME_SIZE 512

// int main(void)
// {
//     // 変数定義
//     char pathname[PATHNAME_SIZE];  // ファイルパス

//     // 変数初期化
//     memset(pathname, '\0', PATHNAME_SIZE); 

//     // カレントディレクトリ取得
//     getcwd(pathname, PATHNAME_SIZE);
//     fprintf(stdout,"現在のファイルパス:%s\n", pathname);

//     // カレントディレクトリ変更  
//     chdir("/Users/panti/"); // チェンジディレクトリ
//     getcwd(pathname, PATHNAME_SIZE);
//     fprintf(stdout,"現在のファイルパス:%s\n", pathname);

//     return 0;
// }