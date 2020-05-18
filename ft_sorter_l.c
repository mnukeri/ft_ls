/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:30:16 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/30 15:17:15 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sorter_l(char **s, char **dir)
{
	int		p;
	int		n;
	int		dc;
	char	**st1;
	char	**st2;
	int		steps;

	if (s == NULL)
		return (0);
	dc = ft_dir_count(dir);
	p = 1;
	steps = 0;
	while (p < dc && s[p] != NULL)
	{
		st1 = ft_strsplit(s[p - 1],'`');
		st2 = ft_strsplit(s[p],'`');
		n = ft_strcmp(st1[6], st2[6]);
		ft_strdel(st1);
		ft_strdel(st2);
		if (n == 1)
		{
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		p++;
		steps++;
	}
	return (1);
}
