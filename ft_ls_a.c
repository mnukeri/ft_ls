#include <dirent.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int			ft_array_swap(char *s1, char *s2)
{
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (0);
	temp = ft_memalloc(100);
	ft_strcpy(temp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, temp);
	free(temp);
	return (1);
}

int			ft_sorter(char **s)
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
		/*ft_putstr("s1: ");
		ft_putstr(s[p - 1]);
		ft_putstr(" || s2: ");
		ft_putendl(s[p]);*/
		//if (s[p - 1][0] == '\0')
		//	k = 1;
		if (k == 1)
		{
			ft_putstr("SWITCH UP!");
			ft_putchar('\n');
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		p++;
		steps++;
		//ft_putnbr(steps);
		//ft_putchar(' ');
		//ft_putnbr(p);
		//ft_putchar('\n');
	}
	return (1);
}

int			ft_content_display(char **s)
{
	int		p;
	int		j;

	if (s == NULL)
		return (0);
	p = 0;
	while (s[p])
	{
		j = 0;
		while (s[p][j])
			write(1, &s[p][j++], 1);
		write(1, "\n", 1);
		p++;
		if (s[p] == 0)
			return (1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			**st;
	int				p;
	int				count;
	int				k;

	if (argc < 2)
		return (0);
	if ((pDir = opendir(argv[1])) == NULL)
		return (0);
	p = 0;
	while ((pDirent = readdir(pDir)) != NULL)
		p++;
	closedir(pDir);
	count = p + 1;
	if (!(st = (char**)ft_memalloc_2d(count)))
		return (0);
	ft_bzero(st, count);
	p = 0;
	if ((pDir = opendir(argv[1])) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		k = ft_strlen(pDirent->d_name);
		k += 1;
		if (!(st[p] = ft_memalloc(k)))
			return (0);
		ft_strcpy(st[p], pDirent->d_name);
		p++;
	}
	if (ft_sorter(st) != 1)
		return (0);
	if (ft_content_display(st) != 1)
		return (0);
	free(st);
	closedir(pDir);
	return (0);
}
