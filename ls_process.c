/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:25:34 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/10 17:11:46 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_process(char **dir, int k)
{
	char	**s;
	char	**s1;
	int		p;
	int		*m;
	int		len;

	if (dir == NULL)
		return (0);
	ft_putstr("k: ");
	ft_putendl(ft_itoa(k));
	ft_putchar('\n');
	if (k == 5)
	{
		if (!(s = (char**)ft_memalloc_2d(ls_process_R_count(dir) + 1)))
			return (0);
		p = 0;
		m = &p;
		if (ls_process_R(dir, s, m) != 1)
			return (0);
		++(*m);
		s[*m] = NULL;
		p = 0;
		len = 0;
		while (s[p])
		{
			if (ft_strlen(s[p]) > (size_t)len)
				len = ft_strlen(s[p]);
			p++;
		}
		if (!(s1 = (char**)ft_memalloc_2d(ls_process_R_count(dir) + 1)))
			return (0);
		p = 0;
		while (p < ls_process_R_count(dir) && s[p])
		{
			if (!(s1[p] = ft_memalloc(len + 1)))
				return (0);
			ft_strcpy(s1[p], s[p]);
			p++;
		}
		s1[p] = NULL;
		if (ft_sorter_R(s1, p) != 1)
			return (0);
		p = 0;
		while (p < ls_process_R_count(dir) && s1[p])
		{
			s = ft_strsplit(s1[p],'`');
			len = 0;
			while (s[len])
				ft_putendl(s[len++]);
			p++;
			ft_putchar('\n');
		}
		ft_strdel(s);
		ft_strdel(s1);
		return (1);
	}
	else
	{
		if (!(s = ft_diff_flag(dir, k)))
		{
			ft_putendl("Could not copy flag filtered elements into the array, harde ntwana;");
			return (0);
		}

		if (k == 3)
		{
			if (ft_sorter_t(s, dir) != 1)
			{
				ft_putendl("Could not sort array of directory elements, harde ntwana;");
				return (0);
			}
		}
		else if (k == 2)
		{
			if (ft_sorter_l(s, dir) != 1)
			{
				ft_putendl("Could not sort array of directory elements, harde ntwana;");
				return (0);
			}
		}
		else
		{
			if (ft_sorter(s, dir, k) != 1)
			{
				ft_putendl("Could not sort array of directory elements, harde ntwana;");
				return (0);
			}
		}

		if (ft_content_display(s, dir, k) != 1)
		{
			ft_putendl("Could not display elements after sorting, harde ntwana;");
			return (0);
		}
		ft_strdel(s);
	}
	return (1);
}
