#include "ft_ls.h"

int		ft_disp(char **st)
{
	int		p;

	if (st == NULL)
		return (0);
	p = 0;
	while (st[p])
	{
		//ft_putstr("\033[0;32m");
		ft_putendl(st[p++]);
		//ft_putstr("\033[0m");
	}
	return (1);
}

int		ft_disp_t(char **st)
{
	int		p;
	char	**s;

	if (st == NULL)
		return (0);
	p = 0;
	while (st[p])
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
	while (p >= 0)
		ft_putendl(st[p--]);
	return (1);
}

int		ft_content_display(char **str, int k)
{
	if (k == 3)
	{
		if (ft_disp_t(str) != 1)
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