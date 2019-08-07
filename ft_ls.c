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

//When tested on the MAC, it prints alphabetcially as the OG_ls. so do not stress yourself further, in that regard;
//G_N_L is supposed to be before ft_ls;
//It seems uppercase is supposed to be before lowercase, we're printing according to ascii decimal order;
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
		if (k > 0)
		{
			ft_array_swapper(str[p - 1], str[p]);
			p = 0;
		}
		p++;
	}
}

//For the display, what to still work on is equal space display, optimized for the window/tab;
//On MAC, printing form 'p = 2' prints without any spaces beforehand, check what's stored in the array;
void	ft_display_content(char **s)
{
	int		p;

	p = 2;
	while (s[p])
	{
		if (s[p][0] == '.')
			p++;
		else
		{
			ft_putstr(s[p]);
			ft_putchar(' ');
			ft_putnbr(ft_strcmp(s[p - 1], s[p]));
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
			p++;
		}
	}
}

//Chop this code up to smaller blocks. DO NOT FORGET THE 5x25 rule;
//Now you can work on printing out the various flags for the ls, the basic 'ls' works just fine on the MAC;
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
	st[p][0] = '\0';
	ft_sorter(st);
	ft_display_content(st);
	ft_putchar('\n');
	free(st);
	closedir(pDir);
	return (0);
}
