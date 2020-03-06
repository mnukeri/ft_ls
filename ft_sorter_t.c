#include "ft_ls.h"

int			ft_sorter_t(char **s)
{
	int		p;
	//int		k;
	char	**s1;
	char	**s2;
	int		st1;
	int		st2;
	int		steps;

	if (s == NULL)
		return (0);
	p = 1;
	steps = 0;
	while (s[p])
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
		st1 = 0;
		st2 = 0;
		ft_strdel(s1);
		ft_strdel(s2);
		p++;
		steps++;
	}
	return (1);
}
