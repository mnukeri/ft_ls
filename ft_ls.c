#include <stdio.h>
#include <dirent.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>

void	ft_array_swapper(char *st1, char *st2)
{
	char *temp;

	if (st1 == NULL || st2 == NULL)
		return ;
	temp = ft_memalloc(20);
	ft_strcpy(temp, st1);
	ft_strcpy(st1, st2);
	ft_strcpy(st2, temp);
	free(temp);
}

void	ft_sorter(char **str)
{
	int				p;
	int				k;

	if (str == NULL)
		return ;
	p = 1;
	while (str[p])
	{
		k = ft_strcmp(str[p - 1], str[p]);
		if (k == 1)
		{
			ft_array_swapper(str[p - 1], str[p]);
			p = 0;
		}
		p++;
	}
}

void	ft_display_content(char **s)
{
	int		p;

	p = 0;
	while (s[p])
	{
		if (s[p][0] == '.')
			p++;
		else
		{
			ft_putstr(s[p]);
			ft_putchar('\n');
			p++;
		}
	}
}

int		main(int argc, char **argv)
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
	if (!(st = (char**)malloc(sizeof(char*) * count)))
		return (0);
	ft_memset(st, 0, count);
	p = 0;
	if ((pDir = opendir(argv[1])) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		k = ft_strlen(pDirent->d_name);
		k += 1;
		if (!(st[p] = (char*)malloc(sizeof(char) * k)))
			return (0);
		//ft_bzero(st[p], k);
		ft_memset(st[p], 0, k);
		ft_strcpy(st[p], pDirent->d_name);
		p++;
	}
	ft_sorter(st);
	ft_display_content(st);
	ft_putchar('\n');
	free(st);
	closedir(pDir);
	return (0);
}
