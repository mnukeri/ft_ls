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

static int	ft_dir_count(char **dir)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	int				k;

	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	k = 0;
	while ((pDirent = readdir(pDir)) != NULL)
		k += ft_strlen(pDirent->d_name) + 1;
	closedir(pDir);
	return (k);
}

static char		**ft_dir_copy(char **dir, int k)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			*st;
	char			**s;

	if (!(st = ft_memalloc(k)))
		return (0);
	ft_bzero(st, k);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		ft_strcat(st, pDirent->d_name);
		ft_strcat(st, " ");
	}
	if (!(s = ft_strsplit(st, ' ')))
	{
		ft_putendl("could not string split");
		return (0);
	}
	return (s);
}

int			main(int argc, char **argv)
{
	char			**s;
	int				k;

	if (argc < 2)
		return (0);
	if ((k = ft_dir_count(&argv[1])) < 0)
	{
		ft_putendl("Could not count elements in directory");
		return (0);
	}
	if (!(s = ft_dir_copy(&argv[1], k)))
	{
		ft_putendl("Could not copy elements into array");
		return (0);
	}
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
	free(s);
	return (0);
}
