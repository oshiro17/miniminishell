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

int	cd(char	**line)
{
	char	*dir;
	// char	*olddir;
	char	*oldpwd;
	// char	*newpwd;

	if (!line)
		return (0);
	else if (!line[1])
	{
		dir = "/Users/panti";
		// oldpwd = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
		printf("%d\n",chdir(dir));
		// ft_strjoin("PWD=",dir);
	}
	return (0);
}
