#include "ft_ls.h"

int		ft_disp(char **st, char **dir)
{
	int		p;
	int		dc;

	if (st == NULL)
		return (0);
	dc = ft_dir_count(dir);
	ft_putstr("fcd_default_dc: ");
	ft_putendl(ft_itoa(dc));
	p = 0;
	while (p < dc)
	{
		//ft_putstr("\033[0;32m");
		if (st[p][0] != '.')
			ft_putendl(st[p]);
		p++;
		//ft_putstr("\033[0m");
	}
	return (1);
}

int		ft_disp_a(char **st, char **dir)
{
	int		p;
	int		dc;

	if (!st || !dir)
		return (0);
	dc = ft_dir_count(dir);
	ft_putstr("fcd_a_dc: ");
	ft_putendl(ft_itoa(dc));
	p = 0;
	while (p < dc)
		ft_putendl(st[p++]);
	return (1);
}

int		ft_disp_ti(char **st, char **dir)
{
	int		p;
	int		dc;
	char	**s;

	if (st == NULL)
		return (0);
	dc = ft_dir_count(dir);
	ft_putstr("fcd_ti_dc: ");
	ft_putendl(ft_itoa(dc));
	p = 0;
	while (p < dc)
	{
		if (st[p][0] != '.')
		{
			s = ft_strsplit(st[p],'`');
			ft_putendl(s[0]);
		}
		p++;
	}
	ft_strdel(s);
	return (1);
}

int		ft_disp_r(char **st, char **dir)
{
	int		dc;

	if (st == NULL)
		return (0);
	dc = ft_dir_count(dir);
	ft_putstr("fcd_r_dc: ");
	ft_putendl(ft_itoa(dc));
	dc -= 1;
	while (dc >= 0)
	{
		if (st[dc][0] != '.')
			ft_putendl(st[dc]);
		dc--;
	}
	return (1);
}

int		ft_fst(char **st, char **dir)
{
	int		p;
	int		f_total;
	char	**s;
	int		dc;

	if (!st)
		return (0);
	dc = ft_dir_count(dir);
	f_total = 0;
	p = 0;
	while (p < dc)
	{
		s = ft_strsplit(st[p],'`');
		f_total += ft_atoi(s[4]);
		p++;
	}
	ft_strdel(s);
	return (f_total);
}

int		ft_disp_l(char **st, char **dir)
{
	int		p;
	int		k;
	int		dc;
	char	**s;

	if (!st)
		return (0);
	k = ft_fst(st, dir);
	ft_putstr("total: ");
	ft_putendl(ft_itoa(k));
	dc = ft_dir_count(dir);
	ft_putstr("fdl_dc: ");
	ft_putendl(ft_itoa(dc));
	p = 0;
	while (p < dc)
	{
		s = ft_strsplit(st[p],'`');
		if (s[6][0] != '.')
		{
			k = 0;
			while (s[k])
			{
				ft_putstr(s[k++]);
				if (k <= 6)
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		p++;
	}
	ft_strdel(s);
	return (1);
}

int		ft_content_display(char **str, char **dir, int k)
{
	if (k == 1)
	{
		if (ft_disp_a(str, dir) != 1)
			return (0);
		return (1);
	}
	if (k == 2)
	{
		if (ft_disp_l(str, dir) != 1)
			return (0);
		return (1);
	}
	if (k == 3)
	{
		if (ft_disp_ti(str, dir) != 1)
			return (0);
		return (1);
	}
	if (k == 4)
	{
		if (ft_disp_r(str, dir) != 1)
			return (0);
		return (1);
	}
	if (ft_disp(str, dir) != 1)
		return (0);
	return (1);
}