#include "minimini.h"
void    put_env(char **env)
{
       int i = 0;
    while (env[i])
    {
        printf("%s\n",env[i]);
        i++;
    }
}

int main(int argc,char **argv, char **env)
{
    (void)argc;
    (void)argv;

    pjkut_env(env);
    printf("%d, %s\n",__LINE__, __FILE__);
    printf("%d, %s\n",__LINE__, __FILE__);
    printf("LINE == %d, FILE == %s\n", __LINE__, __FILE__);
    return (0);
}
