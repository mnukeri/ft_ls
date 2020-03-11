#include "ft_ls.h"

int		ft_disp(char **st)
{
	int		p;
	int		dc;

	if (st == NULL)
		return (0);
	dc = 0;
	while (st[dc])
		dc++;
	p = 0;
	while (p < dc)
	{
		//ft_putstr("\033[0;32m");
		ft_putendl(st[p++]);
		//ft_putstr("\033[0m");
	}
	return (1);
}

int		ft_disp_ti(char **st)
{
	int		p;
	int		dc;
	char	**s;

	if (st == NULL)
		return (0);
	dc = 0;
	while (st[dc])
		dc++;
	p = 0;
	while (p < dc)
	{
		s = ft_strsplit(st[p],'`');
		ft_putendl(s[0]);
		p++;
	}
	ft_strdel(s);
	return (1);
}

int		ft_disp_r(char **st)
{
	int		p;

	if (st == NULL)
		return (0);
	p = 0;
	while (st[p])
		p++;
	p--;
	while (p >= 0)
		ft_putendl(st[p--]);
	return (1);
}

int		ft_fst(char **st)
{
	int		p;
	int		f_total;
	char	**s;

	if (!st)
		return (0);
	f_total = 0;
	p = 0;
	while (st[p])
	{
		s = ft_strsplit(st[p],'`');
		f_total += ft_atoi(s[4]);
		ft_strdel(s);
		p++;
	}
	return (f_total);
}

int		ft_disp_l(char **st)
{
	int		p;
	int		k;

	if (!st)
		return (0);
	k = ft_fst(st);
	ft_putstr("total: ");
	ft_putendl(ft_itoa(k));
	p = 0;
	while (st[p])
	{
		k = 0;
		while (st[p][k])
		{
			if (st[p][k] == '`')
				ft_putchar(' ');
			else
				ft_putchar(st[p][k]);
			k++;
		}
		ft_putchar('\n');
		p++;
	}
	return (1);
}

int		ft_content_display(char **str, int k)
{
	if (k == 2)
	{
		if (ft_disp_l(str) != 1)
			return (0);
		return (1);
	}
	if (k == 3)
	{
		if (ft_disp_ti(str) != 1)
			return (0);
		return (1);
	}
	if (k == 4)
	{
		if (ft_disp_r(str) != 1)
			return (0);
		return (1);
	}
	if (ft_disp(str) != 1)
		return (0);
	return (1);
}