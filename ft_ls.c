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
		printf("%d\n", k);
		if (k > 0)
		{
			ft_array_swapper(str[p], str[p - 1]);
			p = 0;
		}
		p++;
	}
}

int		main(int argc, char **argv)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			**st;
	int				p;

	if (argc < 2)
	{
		printf("Usage: a.out <dirname>\n");
		return (1);
	}
	pDir = opendir(argv[1]);
	if (pDir == NULL)
	{
		printf("cannot open directory [%s]\n", argv[1]);
		return (1);
	}
	if (!(st = (char**)malloc(sizeof(char*) * (15))))
	{
		printf("Couldn't set first memory bank.");
		return (0);
	}
	ft_bzero(st, 15);
	p = 0;
	while (p < 15)
	{
		if (!(st[p] = ft_memalloc(20)))
		{
			printf("Couldn't expand memory block p: %d\n", p);
			return (0);
		}
		p++;
	}
	p = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		ft_strcpy(st[p], pDirent->d_name);
		p++;
	}
	st[p] = '\0';
	ft_sorter(st);
	p = 0;
	while (st[p])
	{
		if (st[p][0] == '.')
			p++;
		else
		{
			ft_putstr(st[p]);
			//ft_putchar(' ');
			//ft_putnbr(ft_strlen(st[p]));
			ft_putchar('\t');
			p++;
		}
	}
	ft_putchar('\n');
	free(st);
	closedir(pDir);
	return (0);
}
