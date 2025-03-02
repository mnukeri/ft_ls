#include "ft_ls.h"

int			ft_sorter_t(char **s, char **dir)
{
	int		p;
	int		dc;
	char	**s1;
	char	**s2;
	int		st1;
	int		st2;
	int		steps;

	if (s == NULL)
		return (0);
	dc = ft_dir_count(dir);
	p = 1;
	steps = 0;
	while (p < dc)
	{
		s1 = ft_strsplit(s[p - 1],'`');
		s2 = ft_strsplit(s[p],'`');
		st1 = ft_atoi(s1[1]);
		st2 = ft_atoi(s2[1]);
		if (st1 < st2)
		{

			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		ft_strdel(s1);
		ft_strdel(s2);
		p++;
		steps++;
	}
	return (1);
}
