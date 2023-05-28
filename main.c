#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

char	**ft_split(char *c);


int	main(int argc, char **argv, char**env)
{
	// char	*line_tmp;
	char	**line;
	(void)argc;
	(void)argv;
	line = NULL;

    // getcwd(pathname, PATHNAME_SIZE);
    // fprintf(stdout,"現在のファイルパス:%s\n", pathname);
	// printf("%d\n",chdir("/Users"));
	//     getcwd(pathname, PATHNAME_SIZE);
    // fprintf(stdout,"現在のファイルパス:%s\n", pathname);
	
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
			if (!strcmp(line[0], "cd"))
			{
				;
			}
			if (!strcmp(line[0], "echo"))
			{
				echo(line);
			}
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