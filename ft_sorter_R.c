#include "ft_ls.h"

int			ft_sorter_R(char **s, int dc)
{
	int		p;
	int		n;
	int		steps;
	char	**s1;
	char	**s2;
	char	*st1;
	char	*st2;

	if (!s)
		return (0);
	p = 1;
	steps = 0;
	while (p < dc && s[p])
	{
		s1 = ft_strsplit(s[p - 1], '`');
		s2 = ft_strsplit(s[p], '`');
		st1 = s1[0];
		st2 = s2[0];
		if (st1[0] != '.' || st2[0] != '.')
		{
			ft_strclr(st1);
			ft_strclr(st2);
			ft_strdel(s1);
			ft_strdel(s2);
			p++;
			continue ;
		}
		n = ft_strcmp(s1[0], s2[0]);
		if (n == 1)
		{
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		ft_strclr(st1);
		ft_strclr(st2);
		ft_strdel(s1);
		ft_strdel(s2);
		p++;
		steps++;
	}
	return (1);
}