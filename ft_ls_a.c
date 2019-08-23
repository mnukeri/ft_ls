#include <dirent.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	ft_array_swap(char *s1, char *s2)
{
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(temp = ft_strnew(ft_strlen(s1))))
		return (0);
	ft_strcpy(temp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, temp);
	free(temp);
	return (1);
}

static int	ft_sorter(char **s)
{
	int		p;
	int		k;
	int		steps;

	if (s == NULL)
		return (0);
	p = 1;
	steps = 0;
	while (s[p])
	{
		k = ft_strcmp(s[p - 1], s[p]);
		if (k == 1)
		{
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		p++;
		steps++;
	}
	return (1);
}

static int	ft_content_display(char **s)
{
	int		p;

	if (s == NULL)
		return (0);
	p = 0;
	while (s[p])
	{
		ft_putendl(s[p]);
		p++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			*st;
	char			**s;
	int				p;
	int				count;
	int				k;

	if (argc < 2)
		return (0);
	if ((pDir = opendir(argv[1])) == NULL)
		return (0);
	p = 0;
	k = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		k += ft_strlen(pDirent->d_name) + 1;
		p++;
	}
	closedir(pDir);
	count = p + 1;
	if (!(st = ft_memalloc(k)))
		return (0);
	ft_bzero(st, k);
	if ((pDir = opendir(argv[1])) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		ft_strcat(st, pDirent->d_name);
		ft_strcat(st, " ");
	}
	s = ft_strsplit(st, ' ');
	if (ft_sorter(s) != 1)
	{
		ft_putendl("Could not sort");
		return (0);
	}
	if (ft_content_display(s) != 1)
	{
		ft_putendl("could not display after sorting");
		return (0);
	}
	free(st);
	closedir(pDir);
	return (0);
}
